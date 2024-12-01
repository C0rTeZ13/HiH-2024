using ServiceLayer.Models;

namespace API.Models
{
    public class DrawEstimatesRequest
    {
        public int OriginImageId { get; set; }
        public uint StandardSizeMillimeters { get; set; }
        public string StandardDetail { get; set; }
        public uint TorchWidthMillimeters { get; set; }
        public uint TorchTakeoffMillimeters { get; set; }
        public uint CoastPerLiter { get; set; }
        public uint PaintMillilitersPerSquareMeter { get; set; }
    }
}
