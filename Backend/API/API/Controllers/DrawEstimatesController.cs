using API.Models;
using Microsoft.AspNetCore.Mvc;

namespace API.Controllers
{
    [ApiController]
    [Route("[controller]")]
    public class DrawEstimatesController : ControllerBase
    {
        public DrawEstimatesController()
        {
            
        }

        [Produces<DrawEstimatesResponse>]
        [HttpPost]
        public DrawEstimatesResponse DrawEstimates([FromBody]DrawEstimatesRequest request)
        {
            return null;
        }
    }
}
