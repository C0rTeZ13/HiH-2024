namespace ServiceLayer.Constants
{
    public static class AppRoles
    {
        public const string Admin = "Administrator";

        public static IEnumerable<string> AllRoles()
            => [Admin];
    }
}
