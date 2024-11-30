using Microsoft.Extensions.Configuration;

namespace ServiceLayer.Services.Concrete
{
    public class FilePathService : IFilePathService
    {
        private readonly string _originFilesDir;
        private readonly string _outFilesDir;
        private const string _dateFormat = "dd.MM.yyyy.hh.mm.ss";

        public FilePathService(IConfiguration configuration)
        {
            _originFilesDir = configuration["FilesStorage:Origin"];
            _outFilesDir = configuration["FilesStorage:Out"];
        }

        public string CreateOriginFilePath(string fileName)
        {
            return Path.Combine(_originFilesDir, DateTime.Now.ToString(_dateFormat) + fileName);
        }

        public string CreateOutFilePath(string fileName)
        {
            return Path.Combine(_outFilesDir, DateTime.Now.ToString(_dateFormat) + fileName);
        }
    }
}
