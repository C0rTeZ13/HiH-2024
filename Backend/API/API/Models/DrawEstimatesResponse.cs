using ServiceLayer.Models;

namespace API.Models
{
    public class DrawEstimatesResponse
    {
        public string ImageFile { get; set; }
        public IEnumerable<DetailInfo> DetailsEstimates { get; set; }
        public uint StandardSizeMillimeters { get; set; }
        public string StandardDetail { get; set; }
        public uint TorchWidthMillimeters { get; set; }
        public uint TorchTakeoffMillimeters { get; set; }
        public uint CoastPerLiter { get; set; }
    }
}
