using DataLayer.Entities;
using Microsoft.AspNetCore.Identity;

namespace ServiceLayer.Services.Authentication.Concrete
{
    public class SignInService : ISignInService
    {
        private readonly UserManager<AppUser> _userManager;

        private const string _login_fail_message = "Invalid Credentials";

        public SignInService(UserManager<AppUser> userManager)
        {
            _userManager = userManager;
        }

        public async Task<AppUser> SignUserAsync(string username, string password, CancellationToken cancellationToken)
        {
            AppUser? user = await _userManager.FindByNameAsync(username);

            if (user == null)
            {
                throw new Exception(_login_fail_message);
            }

            bool isPasswordValid = await _userManager.CheckPasswordAsync(user, password);

            if (!isPasswordValid)
            {
                throw new Exception(_login_fail_message);
            }
            return user;
        }
    }
}
