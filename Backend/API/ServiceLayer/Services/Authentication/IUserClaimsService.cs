using DataLayer.Entities;
using System.Security.Claims;

namespace ServiceLayer.Services.Authentication
{
    public interface IUserClaimsService
    {
        public Task<IEnumerable<Claim>> GetUserClaimsAsync(AppUser user, CancellationToken cancellationToken);
    }
}
