using ServiceLayer.Models;

namespace ServiceLayer.Services
{
    public interface IDetailsPaintingAreaService
    {
        public IEnumerable<DetailPaintingArea> GetDetailPaintingAreas(DrawEstimatesInDto inDto, string outFilePath);
    }
}
