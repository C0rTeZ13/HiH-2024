using DataLayer;
using DataLayer.Entities;
using Microsoft.EntityFrameworkCore;
using ServiceLayer.Models;

namespace ServiceLayer.Services.Concrete
{
    public class EstimatesStorageService : IEstimatesStorageService
    {
        private readonly AppDbContext _dbContext;

        public EstimatesStorageService(AppDbContext dbbContext)
        {
            _dbContext = dbbContext;
        }

        public Estimates? GetEstimates(int id)
        {
            return _dbContext.Estimates
                 .AsNoTracking()
                 .Include(e => e.Details)
                 .FirstOrDefault(e => e.EstimatesID == id);
        }

        public IEnumerable<EstimatesListDto> GetUserEstimates(string userId)
        {
            return _dbContext.Estimates
                 .AsNoTracking()
                 .Where(e => e.UserId == userId)
                 .Select(u => new EstimatesListDto()
                 {
                     Id = u.EstimatesID,
                     DateTime = u.DateTime,
                     Name = Path.GetFileName(u.OriginFilePath)
                 });
        }

        public void SaveEstimates(DrawEstimatesInDto inDto, DrawEstimatesOutDto outDto, string userId)
        {
            Estimates estimates = new Estimates()
            {
                DateTime = DateTime.UtcNow,
                OriginFilePath = inDto.ImageFilePath,
                ResultFilePath = outDto.ImageFilePath,
                UserId = userId,
                StandardDetail = inDto.StandardDetail.ToString(),
                CoastPerLiter = inDto.CoastPerLiter,
                Details = outDto.DetailInfos.Select(d => new Detail
                {
                    Coast = d.Coast,
                    InternalId = d.Id,
                    PaintRateMilliliters = d.PaintRateMilliliters,
                    SquareMillimeters = d.SquareMillimeters
                }).ToList(),
                PaintMillilitersPerSquareMeter = inDto.PaintMillilitersPerSquareMeter,
                StandardSizeMillimeters = inDto.StandardSizeMillimeters,
                TorchTakeoffMillimeters = inDto.TorchTakeoffMillimeters,
                TorchWidthMillimeters = inDto.TorchWidthMillimeters

            };

            _dbContext.Add(estimates);
            _dbContext.SaveChanges();
        }
    }
}
