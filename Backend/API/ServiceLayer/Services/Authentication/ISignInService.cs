using DataLayer.Entities;

namespace ServiceLayer.Services.Authentication
{
    public interface ISignInService
    {
        public Task<AppUser> SignUserAsync(string username, string password, CancellationToken cancellationToken);
    }
}
