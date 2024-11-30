using ServiceLayer.Models;
using System;

namespace ServiceLayer.Services.Concrete
{
    public class CreateEstimatesService : ICreateEstimatesService
    {
        private readonly IDetailsPaintingAreaService _detailAreaService;

        public CreateEstimatesService(IDetailsPaintingAreaService detailAreaService)
        {
            _detailAreaService = detailAreaService;
        }

        public DrawEstimatesOutDto GetDrawEstimates(DrawEstimatesInDto inDto, string outFilePath)
        {
            IEnumerable<DetailPaintingArea> detailAreas = _detailAreaService.GetDetailPaintingAreas(inDto, outFilePath);
            IEnumerable<DetailInfo> detailInfos = detailAreas.Select(area => GetDetailInfo(area, inDto));
            return new DrawEstimatesOutDto()
            {
                DetailsEstimates = detailInfos,
                ImageFilePath = outFilePath
            };
        }

        private DetailInfo GetDetailInfo(DetailPaintingArea paintingArea, DrawEstimatesInDto inDto)
        {
            uint paintRateMilliliters = paintingArea.SquareMillimeters * inDto.PaintMillilitersPerSquareMeter / 1_000_000;
            decimal coast = paintRateMilliliters * inDto.CoastPerLiter / 1_000;
            return new DetailInfo()
            {
                Id = paintingArea.Id,
                Coast = coast,
                PaintRateMilliliters = paintRateMilliliters,
                SquareMillimeters = paintingArea.SquareMillimeters
            };
        }
    }
}
