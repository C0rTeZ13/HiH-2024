using Microsoft.AspNetCore.Identity;

namespace ServiceLayer.Extensions
{
    public static class IdentityResultExtensions
    {
        public static string GetMessage(this IdentityResult identity_result)
        {
            return identity_result.Succeeded ?
                "Succeeded" :
                string.Join(
                    ", ",
                    identity_result.Errors.Select(x => $"{x.Code} : {x.Description}").ToList()
                    );
        }
    }
}
