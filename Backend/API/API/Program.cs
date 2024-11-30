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
            builder.Services.AddEndpointsApiExplorer();
            builder.Services.AddSwaggerGen();

            builder.Services.AddScoped<ICreateEstimatesService, CreateEstimatesService>();
            builder.Services.AddScoped<IDetailsPaintingAreaService, TestDetailsPaintingAreaService>();
            builder.Services.AddScoped<IFilePathService, FilePathService>();
            builder.Services.AddScoped<IFileService, FileService>();

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
