using DataLayer.Entities;
using ServiceLayer.Models;

namespace ServiceLayer.QueryObjects
{
    public static class UserDtoSelect
    {
        public static IQueryable<UserDto> MapToDto(this IQueryable<AppUser> users)
        {
            return users.Select(user => new UserDto()
            {
                Id = user.Id,
                UserName = user.UserName,
                Password = null
            });
        }
    }
}
