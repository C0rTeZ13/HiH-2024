using ServiceLayer.Models;

namespace ServiceLayer.Services.Concrete
{
    public class TestDetailsPaintingAreaService : IDetailsPaintingAreaService
    {
        // заглушка вместо скрипта, генерирует рандомную смету, записывает тот же файл без изменений
        public IEnumerable<DetailPaintingArea> GetDetailPaintingAreas(DrawEstimatesInDto inDto, string outFilePath)
        {
            File.Copy(inDto.ImageFilePath, outFilePath);

            Random rand = new Random();
            return Enumerable.Range(0, 5).Select(x => new DetailPaintingArea()
            {
                Id = x,
                SquareMillimeters = (uint)rand.Next(1_000_000, 10_000_000)
            });
        }
    }
}
