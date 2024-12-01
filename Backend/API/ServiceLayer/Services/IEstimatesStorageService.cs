using DataLayer.Entities;
using ServiceLayer.Models;

namespace ServiceLayer.Services
{
    public interface IEstimatesStorageService
    {
        public void SaveEstimates(DrawEstimatesInDto inDto, DrawEstimatesOutDto outDto, string userId);
        public IEnumerable<EstimatesListDto> GetUserEstimates(string userId);
        public Estimates? GetEstimates(int id);
    }
}
