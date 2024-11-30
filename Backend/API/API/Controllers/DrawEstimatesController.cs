using API.Models;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using ServiceLayer.Models;
using ServiceLayer.Services;
using ServiceLayer.Services.Authentication;

namespace API.Controllers
{
    [ApiController]
    [Route("[controller]")]
    [Authorize]
    public class DrawEstimatesController : ControllerBase
    {
        private readonly ICreateEstimatesService _estimatesCreateService;
        private readonly IFileService _fileService;
        private readonly IFilePathService _pathService;
        private readonly IEstimatesStorageService _estimatesStorageService;
        private readonly IUserClaimsService _userClaimsService;

        public DrawEstimatesController(ICreateEstimatesService estimatesCreateService, IFileService fileService, IFilePathService pathService, IEstimatesStorageService estimatesStorageService, IUserClaimsService userClaimsService)
        {
            _estimatesCreateService = estimatesCreateService;
            _fileService = fileService;
            _pathService = pathService;
            _estimatesStorageService = estimatesStorageService;
            _userClaimsService = userClaimsService;
        }

        [Produces<DrawEstimatesResponse>]
        [HttpPost]
        public DrawEstimatesResponse DrawEstimates(DrawEstimatesRequest request)
        {
            string originImageFilePath = _pathService.CreateOriginFilePath(request.ImageFile.FileName);
            _fileService.WriteFileToPath(request.ImageFile, originImageFilePath);

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

            string outImageFilePath = _pathService.CreateOutFilePath(request.ImageFile.FileName);
            DrawEstimatesOutDto outDto = _estimatesCreateService.GetDrawEstimates(inDto, outImageFilePath);

            string userId = _userClaimsService.GetUserId(User);
            _estimatesStorageService.SaveEstimates(inDto, outDto, userId);

            string outFile = _fileService.GetFileAtPath(outImageFilePath);
            return new DrawEstimatesResponse()
            {
                DetailsEstimates = outDto.DetailInfos,
                ImageFile = outFile
            };
        }
    }
}
