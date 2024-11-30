namespace DataLayer.Entities
{
    public class Estimates
    {
        public int EstimatesID { get; set; }
        public string OriginFilePath { get; set; }
        public string ResultFilePath { get; set; }
        public DateTime DateTime { get; set; }
        public uint StandardSizeMillimeters { get; set; }
        public uint TorchWidthMillimeters { get; set; }
        public uint TorchTakeoffMillimeters { get; set; }
        public uint CoastPerLiter { get; set; }
        public uint PaintMillilitersPerSquareMeter { get; set; }
        public ICollection<Detail> Details { get; set; }
        public string UserId { get; set; }
    }
}
