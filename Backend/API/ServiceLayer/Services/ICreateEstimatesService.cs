using ServiceLayer.Models;

namespace ServiceLayer.Services
{
    public interface ICreateEstimatesService
    {
        public DrawEstimatesOutDto GetDrawEstimates(DrawEstimatesInDto inDto, string outFilePath);
    }
}
