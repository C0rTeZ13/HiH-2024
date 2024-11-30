using API.Models;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using ServiceLayer.Services;
using ServiceLayer.Services.Authentication;

namespace API.Controllers
{
    [ApiController]
    [Route("[controller]/[action]")]
    [Authorize]
    public class ImageController : ControllerBase
    {
        private readonly IFileService _fileService;
        private readonly IFilePathService _pathService;
        private readonly IUserClaimsService _userClaimsService;
        private readonly IUploadImageService _uploadImageService;

        public ImageController(IFileService fileService, IFilePathService pathService, IUserClaimsService userClaimsService, IUploadImageService uploadImageService)
        {
            _fileService = fileService;
            _pathService = pathService;
            _userClaimsService = userClaimsService;
            _uploadImageService = uploadImageService;
        }

        [HttpPost]
        public ActionResult<UploadedImageResponse> UploadImage(IFormFile file)
        {
            string originImageFilePath = _pathService.CreateOriginFilePath(file.FileName);
            _fileService.WriteFileToPath(file, originImageFilePath);
            int imageId = _uploadImageService.SaveImageInfo(originImageFilePath, file.FileName, _userClaimsService.GetUserId(User));
            return new UploadedImageResponse()
            {
                Id = imageId,
                Name = file.FileName,
            };
        }
    }
}
