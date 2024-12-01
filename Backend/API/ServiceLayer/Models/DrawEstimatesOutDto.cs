using DataLayer.Entities;

namespace ServiceLayer.Models
{
    public class DrawEstimatesOutDto
    {
        public string ImageFilePath { get; set; }
        public IEnumerable<DetailInfo> DetailInfos { get; set; }
    }
}
