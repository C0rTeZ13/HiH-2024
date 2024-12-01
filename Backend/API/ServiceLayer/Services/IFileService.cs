using Microsoft.AspNetCore.Http;

namespace ServiceLayer.Services
{
    public interface IFileService
    {
        public void WriteFileToPath(IFormFile file, string path);
        public string GetFileAtPath(string path);
    }
}
