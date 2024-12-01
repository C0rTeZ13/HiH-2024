using ServiceLayer.Models;

namespace ServiceLayer.Services.Authentication
{
    public interface ITokenService
    {
        public Task<TokenDto> CreateTokenAsync(string username, string password, CancellationToken cancellationToken);
    }
}
