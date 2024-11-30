using DataLayer.Entities;
using Microsoft.AspNetCore.Identity;
using System.Security.Claims;

namespace ServiceLayer.Services.Authentication.Concrete
{
    public class UserClaimsService : IUserClaimsService
    {
        private readonly UserManager<AppUser> _userManager;

        public UserClaimsService(UserManager<AppUser> userManager)
        {
            _userManager = userManager;
        }

        public async Task<IEnumerable<Claim>> GetUserClaimsAsync(AppUser user, CancellationToken cancellationToken)
        {
            List<Claim> claims = new() {
                new Claim(ClaimTypes.NameIdentifier, user.Id.ToString()),
                new Claim(ClaimTypes.Name, user.UserName)
            };
            var user_roles = await _userManager.GetRolesAsync(user);
            foreach (var role in user_roles)
            {
                claims.Add(new Claim(ClaimTypes.Role, role));
            }
            return claims;
        }
    }
}
