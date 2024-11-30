using DataLayer;
using DataLayer.Entities;
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
