using ServiceLayer.Models;

namespace ServiceLayer.Services.Authentication
{
    public interface IUserService
    {
        public Task<UserDto?> GetAsync(string id, CancellationToken cancellation_token);
        public Task<IEnumerable<UserDto>> GetAllAsync(CancellationToken cancellation_token);
        public Task<string> CreateAsync(UserDto user);
        public Task DeleteAsync(string id);
    }
}
