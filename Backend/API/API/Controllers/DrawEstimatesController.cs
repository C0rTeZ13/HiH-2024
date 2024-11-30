using API.Models;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using ServiceLayer.Models;
using ServiceLayer.Services;

namespace API.Controllers
{
    [ApiController]
    [Route("[controller]")]
    [Authorize]
    public class DrawEstimatesController : ControllerBase
    {
        private readonly ICreateEstimatesService _estimatesService;
        private readonly IFileService _fileService;
        private readonly IFilePathService _pathService;

        public DrawEstimatesController(ICreateEstimatesService estimatesService, IFileService fileService, IFilePathService pathService)
        {
            _estimatesService = estimatesService;
            _fileService = fileService;
            _pathService = pathService;
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
                StandardSize = new StandardSize()
                {
                    BonnetMillimeters = request.BonnetMillimeters,
                    FrontDoorMillimeters = request.FrontDoorMillimeters,
                    TrunkLidMillimeters = request.TrunkLidMillimeters
                },
                TorchTakeoffMillimeters = request.TorchTakeoffMillimeters,
                TorchWidthMillimeters = request.TorchWidthMillimeters
            };

            string outImageFilePath = _pathService.CreateOutFilePath(request.ImageFile.FileName);
            DrawEstimatesOutDto outDto = _estimatesService.GetDrawEstimates(inDto, outImageFilePath);
            string outFile = _fileService.GetFileAtPath(outImageFilePath);
            return new DrawEstimatesResponse()
            {
                DetailsEstimates = outDto.DetailsEstimates,
                ImageFile = outFile
            };
        }
    }
}
