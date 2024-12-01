using DataLayer;
using DataLayer.Entities;
using Microsoft.EntityFrameworkCore;
using ServiceLayer.Models;

namespace ServiceLayer.Services.Concrete
{
    public class UploadImageService : IUploadImageService
    {
        private readonly AppDbContext _dbContext;

        public UploadImageService(AppDbContext dbContext)
        {
            _dbContext = dbContext;
        }

        public string? GetPathById(int fileId)
        {
            UploadedImage? image = _dbContext.Images.FirstOrDefault(i => i.UploadedImageId == fileId);
            return image?.Path;
        }

        public IEnumerable<UploadedImageDto> GetUserImages(string userId)
        {
            return _dbContext.Images
                .AsNoTracking()
                .Where(i => i.UserId == userId)
                .Select(i => new UploadedImageDto()
                {
                    Id = i.UploadedImageId,
                    Name = i.Name
                });
        }

        public int SaveImageInfo(string path, string name, string userId)
        {
            UploadedImage image = new UploadedImage()
            {
                Path = path,
                Name = name,
                UserId = userId
            };
            _dbContext.Add(image);
            _dbContext.SaveChanges();
            return image.UploadedImageId;
        }
    }
}
