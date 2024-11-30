using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Http.Internal;

namespace ServiceLayer.Services.Concrete
{
    public class FileService : IFileService
    {
        public string GetFileAtPath(string path)
        {
            using StreamReader reader = new StreamReader(path);
            return reader.ReadToEnd();
        }

        public void WriteFileToPath(IFormFile file, string path)
        {
            using StreamWriter writer = new StreamWriter(path);
            file.CopyTo(writer.BaseStream);
            writer.Flush();
        }
    }
}
