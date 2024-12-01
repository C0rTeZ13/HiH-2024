using API.Models;
using DataLayer.Entities;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using ServiceLayer.Models;
using ServiceLayer.Services;
using ServiceLayer.Services.Authentication;

namespace API.Controllers
{
    [ApiController]
    [Route("[controller]/[action]")]
    [Authorize]
    public class DrawEstimatesController : ControllerBase
    {
        private readonly ICreateEstimatesService _estimatesCreateService;
        private readonly IFileService _fileService;
        private readonly IFilePathService _pathService;
        private readonly IEstimatesStorageService _estimatesStorageService;
        private readonly IUserClaimsService _userClaimsService;
        private readonly IUploadImageService _uploadImageService;

        public DrawEstimatesController(ICreateEstimatesService estimatesCreateService, IFileService fileService, IFilePathService pathService, IEstimatesStorageService estimatesStorageService, IUserClaimsService userClaimsService, IUploadImageService uploadImageService)
        {
            _estimatesCreateService = estimatesCreateService;
            _fileService = fileService;
            _pathService = pathService;
            _estimatesStorageService = estimatesStorageService;
            _userClaimsService = userClaimsService;
            _uploadImageService = uploadImageService;
        }

        [Produces<DrawEstimatesResponse>]
        [HttpPost]
        public ActionResult<DrawEstimatesResponse> CreateEstimates(DrawEstimatesRequest request)
        {
            string? originImageFilePath = _uploadImageService.GetPathById(request.OriginImageId);
            if (originImageFilePath == null) return NotFound();

            DrawEstimatesInDto inDto = new()
            {
                ImageFilePath = originImageFilePath,
                CoastPerLiter = request.CoastPerLiter,
                PaintMillilitersPerSquareMeter = request.PaintMillilitersPerSquareMeter,
                StandardSizeMillimeters = request.StandardSizeMillimeters,
                StandardDetail = Enum.Parse<StandardDetail>(request.StandardDetail),
                TorchTakeoffMillimeters = request.TorchTakeoffMillimeters,
                TorchWidthMillimeters = request.TorchWidthMillimeters
            };

            string outImageFilePath = _pathService.CreateOutFilePath(originImageFilePath);
            DrawEstimatesOutDto outDto = _estimatesCreateService.GetDrawEstimates(inDto, outImageFilePath);

            string userId = _userClaimsService.GetUserId(User);
            _estimatesStorageService.SaveEstimates(inDto, outDto, userId);

            string outFile = _fileService.GetFileAtPath(outImageFilePath);
            return new DrawEstimatesResponse()
            {
                DetailsEstimates = outDto.DetailInfos,
                ImageFile = outFile,
                CoastPerLiter = inDto.CoastPerLiter,
                StandardDetail = inDto.StandardDetail.ToString(),
                StandardSizeMillimeters = inDto.StandardSizeMillimeters,
                TorchTakeoffMillimeters = inDto.TorchTakeoffMillimeters,
                TorchWidthMillimeters = inDto.TorchWidthMillimeters
            };
        }

        [HttpGet]
        public IEnumerable<EstimatesListDto> GetList()
        {
            string userId = _userClaimsService.GetUserId(User);
            return _estimatesStorageService.GetUserEstimates(userId);
        }

        [HttpGet]
        public ActionResult<DrawEstimatesResponse> GetEstimates(int id)
        {
            Estimates? estimates = _estimatesStorageService.GetEstimates(id);
            if (estimates == null) return NotFound();

            string userId = _userClaimsService.GetUserId(User);
            if (estimates.UserId != userId) return Forbid();

            return new DrawEstimatesResponse()
            {
                DetailsEstimates = estimates.Details.Select(d => new DetailInfo()
                {
                    Coast = d.Coast,
                    Id = d.EstimatesId,
                    PaintRateMilliliters = d.PaintRateMilliliters,
                    SquareMillimeters = d.SquareMillimeters
                }),
                ImageFile = _fileService.GetFileAtPath(estimates.ResultFilePath),
                CoastPerLiter = estimates.CoastPerLiter,
                StandardDetail = estimates.StandardDetail,
                StandardSizeMillimeters = estimates.StandardSizeMillimeters,
                TorchTakeoffMillimeters = estimates.TorchTakeoffMillimeters,
                TorchWidthMillimeters = estimates.TorchWidthMillimeters
            };
        }
    }
}
