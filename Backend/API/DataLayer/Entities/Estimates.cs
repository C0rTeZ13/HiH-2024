namespace DataLayer.Entities
{
    public class Estimates
    {
        public int EstimatesID { get; set; }
        public string OriginFilePath { get; set; }
        public string ResultFilePath { get; set; }
        public DateTime DateTime { get; set; }
        public string Payload { get; set; }
        public string UserId { get; set; }
    }
}
