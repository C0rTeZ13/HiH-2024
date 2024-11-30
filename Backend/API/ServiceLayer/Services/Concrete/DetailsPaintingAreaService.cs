using ServiceLayer.Models;

namespace ServiceLayer.Services.Concrete
{
    public class DetailsPaintingAreaService : IDetailsPaintingAreaService
    {
        // здесь будет обращение к скрипту
        public IEnumerable<DetailPaintingArea> GetDetailPaintingAreas(DrawEstimatesInDto inDto, string outFilePath)
        {
            throw new NotImplementedException();
        }
    }
}
