namespace ServiceLayer.Services
{
    public interface IUploadImageService
    {
        public int SaveImageInfo(string path, string name, string userId);
        public string GetPathById(int fileId);
    }
}
