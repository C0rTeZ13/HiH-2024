using DataLayer;
using DataLayer.Entities;
using Microsoft.AspNetCore.Identity;
using Microsoft.EntityFrameworkCore;
using ServiceLayer.Extensions;
using ServiceLayer.Models;
using ServiceLayer.QueryObjects;

namespace ServiceLayer.Services.Authentication.Concrete
{
    public class UserService : IUserService
    {
        private readonly UserManager<AppUser> _userManager;
        private readonly AppDbContext _dbContext;

        public UserService(UserManager<AppUser> userManager, AppDbContext dbContext)
        {
            _userManager = userManager;
            _dbContext = dbContext;
        }

        public async Task<string> CreateAsync(UserDto user)
        {
            AppUser appUser = new AppUser()
            {
                UserName = user.UserName,
            };
            var result = await _userManager.CreateAsync(appUser, user.Password);
            if (!result.Succeeded) throw new Exception(result.GetMessage());
            return appUser.Id;
        }


        public async Task DeleteAsync(string id)
        {
            AppUser? user_to_delete = await _userManager.FindByIdAsync(id);
            if (user_to_delete == null) throw new Exception("User not found");

            var result = await _userManager.DeleteAsync(user_to_delete);
            if (!result.Succeeded)
            {
                throw new Exception(result.GetMessage());
            }
        }

        public async Task<UserDto?> GetAsync(string id, CancellationToken cancellation_token)
        {
            return await _dbContext.Users
                .AsNoTracking()
                .MapToDto()
                .FirstOrDefaultAsync(u => u.Id == id, cancellation_token);
        }

        public async Task<IEnumerable<UserDto>> GetAllAsync(CancellationToken cancellation_token)
        {
            return _dbContext.Users
                .AsNoTracking()
                .MapToDto();
        }
    }
}
