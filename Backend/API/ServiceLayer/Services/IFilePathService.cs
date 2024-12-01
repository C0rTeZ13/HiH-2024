namespace ServiceLayer.Services
{
    public interface IFilePathService
    {
        public string CreateOriginFilePath(string fileName);
        public string CreateOutFilePath(string fileName);
    }
}
