namespace ServiceLayer.Services.Concrete
{
    public class FilePathService : IFilePathService
    {
        private const string _originFilesDir = @"C:/Files/Origin";
        private const string _outFilesDir = @"C:/Files/Out";
        private const string _dateFormat = "dd.MM.yyyy.hh.mm.ss";
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
