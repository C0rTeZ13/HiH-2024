using API.Models;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using ServiceLayer.Constants;
using ServiceLayer.Models;
using ServiceLayer.Services.Authentication;

namespace API.Controllers
{
    [ApiController]
    [Route("[controller]/[action]")]
    [Authorize(Roles = AppRoles.Admin)]
    public class UsersController : ControllerBase
    {
        private readonly IUserService _userService;

        public UsersController(IUserService userService)
        {
            _userService = userService;
        }

        [HttpGet]
        public async Task<ActionResult<UserDto>> Get(string id, CancellationToken cancellationToken)
        {
            var user = await _userService.GetAsync(id, cancellationToken);
            if (user == null) return NotFound();
            return user;
        }

        [HttpGet]
        public async Task<IEnumerable<UserDto>> GetAll(CancellationToken cancellationToken)
        {
            return await _userService.GetAllAsync(cancellationToken);
        }

        [HttpPost]
        public async Task<ActionResult<UserDto>> Create(CreateUserRequest request, CancellationToken cancellationToken)
        {
            UserDto dto = new()
            {
                Password = request.Password,
                UserName = request.UserName
            };
            string created_id = await _userService.CreateAsync(dto);
            return await _userService.GetAsync(created_id, cancellationToken);
        }

        [HttpDelete]
        public async Task<IActionResult> Delete(string id)
        {
            if (await _userService.GetAsync(id, CancellationToken.None) == null)
                return NotFound();
            await _userService.DeleteAsync(id);
            return Ok();
        }
    }
}
