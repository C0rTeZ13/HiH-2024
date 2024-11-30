using DataLayer.Entities;
using ServiceLayer.Models;

namespace ServiceLayer.Services
{
    public interface IEstimatesStorageService
    {
        public void SaveEstimates(DrawEstimatesInDto inDto, DrawEstimatesOutDto outDto, string userId);
    }
}
