using DataLayer;
using Microsoft.AspNetCore.Authentication;
using Microsoft.AspNetCore.Authorization;
using ServiceLayer.Constants;
using ServiceLayer.Services.Concrete;
using ServiceLayer.Services;
using System.Security.Claims;
using ServiceLayer.Models.Settings;
using Microsoft.EntityFrameworkCore;
using Microsoft.AspNetCore.Identity;
using DataLayer.Entities;
using Microsoft.OpenApi.Models;
using Microsoft.AspNetCore.Authentication.JwtBearer;
using Microsoft.IdentityModel.Tokens;
using System.Text;
using ServiceLayer.Services.Authentication.Concrete;
using ServiceLayer.Services.Authentication;

namespace API
{
    public static class IServiceCollectionExtensions
    {
        public static void AddAppAuthorization(this IServiceCollection services)
        {

        }

        public static void AddAppServices(this IServiceCollection services)
        {
            services.AddScoped<ICreateEstimatesService, CreateEstimatesService>();
            services.AddScoped<IDetailsPaintingAreaService, TestDetailsPaintingAreaService>();
            services.AddScoped<IFilePathService, FilePathService>();
            services.AddScoped<IFileService, FileService>();

            services.AddScoped<IUserService, UserService>();
            services.AddScoped<ISignInService, SignInService>();
            services.AddScoped<ITokenService, JwtTokenService>();
            services.AddScoped<IUserClaimsService, UserClaimsService>();
        }

        public static void ConfigureApp(this IServiceCollection services, IConfiguration configuration)
        {
            services.Configure<SuperuserSettings>(configuration.GetSection("AdminUser"));
            services.Configure<JwtSettings>(configuration.GetSection("JwtTokens"));
        }

        public static void AddAppDbContext(this IServiceCollection services, IConfiguration configuration)
        {
            services.AddDbContext<AppDbContext>(options
               => options.UseNpgsql(configuration.GetConnectionString("DefaultConnection")));
        }


        public static void AddAppIdentity(this IServiceCollection services)
        {
            services.AddIdentityCore<AppUser>(options =>
            {
                options.SignIn.RequireConfirmedAccount = false;
                options.User.RequireUniqueEmail = false;
                options.Password.RequireDigit = false;
                options.Password.RequiredLength = 6;
                options.Password.RequireNonAlphanumeric = false;
                options.Password.RequireUppercase = false;
                options.Password.RequireLowercase = false;
            })
            .AddRoles<IdentityRole>()
            .AddEntityFrameworkStores<AppDbContext>();
        }

        public static void AddAppAuthentication(this IServiceCollection services, IConfiguration configuration)
        {

            services.AddAuthentication("Bearer")
            .AddJwtBearer(JwtBearerDefaults.AuthenticationScheme, options =>
                options.TokenValidationParameters = new TokenValidationParameters()
                {
                    ValidateIssuer = false,
                    ValidateAudience = false,
                    ValidateLifetime = true,
                    ValidateIssuerSigningKey = true,
                    ClockSkew = TimeSpan.Zero,
                    IssuerSigningKey = new SymmetricSecurityKey(
                        Encoding.UTF8.GetBytes(configuration["JwtTokens:Key"])
                    )
                });
        }

        public static void AddAppSwagger(this IServiceCollection services)
        {
            services.AddEndpointsApiExplorer();
            services.AddSwaggerGen(opt =>
            {
                opt.AddSecurityDefinition("Bearer", new OpenApiSecurityScheme
                {
                    In = ParameterLocation.Header,
                    Description = "Please enter token",
                    Name = "Authorization",
                    Type = SecuritySchemeType.Http,
                    BearerFormat = "JWT",
                    Scheme = "bearer"
                });
                opt.AddSecurityRequirement(new OpenApiSecurityRequirement
                {
                    {
                        new OpenApiSecurityScheme
                        {
                            Reference = new OpenApiReference
                            {
                                Type=ReferenceType.SecurityScheme,
                                Id="Bearer"
                            }
                        },
                        new string[]{}
                    }
                });
            });
        }
    }
}
