using DataLayer.Entities;
using ServiceLayer.Models;

namespace API.Models
{
    public class DrawEstimatesResponse
    {
        public string ImageFile { get; set; }
        public IEnumerable<DetailInfo> DetailsEstimates { get; set; }
    }
}
