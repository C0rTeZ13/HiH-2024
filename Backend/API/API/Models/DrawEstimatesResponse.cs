namespace API.Models
{
    public class DrawEstimatesResponse 
    {
        public IFormFile ImageFile { get; set; }
        public IEnumerable<DetailInfo> DetailsEstimates { get; set; }
        public DrawEstimatesResponse(IEnumerable<DetailInfo> detailsEstimates) 
        {
            DetailsEstimates = detailsEstimates;
        }
    }
}
