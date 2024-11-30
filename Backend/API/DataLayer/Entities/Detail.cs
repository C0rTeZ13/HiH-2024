namespace DataLayer.Entities
{
    public class Detail
    {
        public int InternalId { get; set; }
        public uint SquareMillimeters { get; set; }
        public uint PaintRateMilliliters { get; set; }
        public decimal Coast { get; set; }
        public int EstimatesId { get; set; }
    }
}
