using DataLayer;
using Microsoft.EntityFrameworkCore;
using ServiceLayer.Services;
using ServiceLayer.Services.Concrete;

namespace API
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var builder = WebApplication.CreateBuilder(args);

            builder.Services.AddControllers();
            builder.Services.AddAppSwagger();
            builder.Services.AddAppServices();
            builder.Services.AddAppIdentity();
            builder.Services.ConfigureApp(builder.Configuration);
            builder.Services.AddAppDbContext(builder.Configuration);
            builder.Services.AddAppAuthentication(builder.Configuration);
            builder.Services.AddHostedService<DatabaseInitService>();

            builder.Services.AddDbContext<AppDbContext>(options
               => options.UseNpgsql(builder.Configuration.GetConnectionString("DefaultConnection")));

            var app = builder.Build();

            app.UseSwagger();
            app.UseSwaggerUI();
            app.UseHttpsRedirection();
            app.UseAuthorization();
            app.MapControllers();

            app.Run();
        }
    }
}
