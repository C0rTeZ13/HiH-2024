namespace ServiceLayer.Models
{
    public class DrawEstimatesInDto
    {
        public string ImageFilePath { get; set; }
        public StandardSize StandardSize { get; set; }
        public uint TorchWidthMillimeters { get; set; }
        public uint TorchTakeoffMillimeters { get; set; }
        public uint CoastPerLiter { get; set; }
        public uint PaintMillilitersPerSquareMeter { get; set; }
    }
}
