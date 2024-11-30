using ServiceLayer.Models;

namespace API.Models
{
    public class DrawEstimatesRequest
    {
        public IFormFile ImageFile { get; set; }
        public uint? FrontDoorMillimeters { get; set; }
        public uint? BonnetMillimeters { get; set; }
        public uint? TrunkLidMillimeters { get; set; }
        public uint TorchWidthMillimeters { get; set; }
        public uint TorchTakeoffMillimeters { get; set; }
        public uint CoastPerLiter { get; set; }
        public uint PaintMillilitersPerSquareMeter { get; set; }
    }
}
