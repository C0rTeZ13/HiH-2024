using DataLayer.Configuration;
using DataLayer.Entities;
using Microsoft.AspNetCore.Identity.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore;

namespace DataLayer
{
    public class AppDbContext : IdentityDbContext<AppUser>
    {
        public DbSet<Estimates> Estimates { get; set; }
        public DbSet<UploadedImage> Images { get; set; }
        public AppDbContext() : base() { }
        public AppDbContext(DbContextOptions dbContextOptions) : base(dbContextOptions) { }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseNpgsql();
        }

        protected override void OnModelCreating(ModelBuilder builder)
        {
            base.OnModelCreating(builder);
            builder.ApplyConfiguration(new AppUserConfig());           
            builder.ApplyConfiguration(new DetailConfig());           
        }
    }
}
