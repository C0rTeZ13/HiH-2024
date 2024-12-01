using ServiceLayer.Models;

namespace ServiceLayer.Services
{
    public interface IUploadImageService
    {
        public int SaveImageInfo(string path, string name, string userId);
        public string GetPathById(int fileId);
        public IEnumerable<UploadedImageDto> GetUserImages(string userId);
        public Stream? GetFileStream(int estimatesId);
    }
}
