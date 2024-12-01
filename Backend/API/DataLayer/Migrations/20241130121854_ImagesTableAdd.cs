using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace DataLayer.Migrations
{
    /// <inheritdoc />
    public partial class ImagesTableAdd : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_UploadedImage_AspNetUsers_UserId",
                table: "UploadedImage");

            migrationBuilder.DropPrimaryKey(
                name: "PK_UploadedImage",
                table: "UploadedImage");

            migrationBuilder.RenameTable(
                name: "UploadedImage",
                newName: "Images");

            migrationBuilder.RenameIndex(
                name: "IX_UploadedImage_UserId",
                table: "Images",
                newName: "IX_Images_UserId");

            migrationBuilder.AddPrimaryKey(
                name: "PK_Images",
                table: "Images",
                column: "UploadedImageId");

            migrationBuilder.AddForeignKey(
                name: "FK_Images_AspNetUsers_UserId",
                table: "Images",
                column: "UserId",
                principalTable: "AspNetUsers",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_Images_AspNetUsers_UserId",
                table: "Images");

            migrationBuilder.DropPrimaryKey(
                name: "PK_Images",
                table: "Images");

            migrationBuilder.RenameTable(
                name: "Images",
                newName: "UploadedImage");

            migrationBuilder.RenameIndex(
                name: "IX_Images_UserId",
                table: "UploadedImage",
                newName: "IX_UploadedImage_UserId");

            migrationBuilder.AddPrimaryKey(
                name: "PK_UploadedImage",
                table: "UploadedImage",
                column: "UploadedImageId");

            migrationBuilder.AddForeignKey(
                name: "FK_UploadedImage_AspNetUsers_UserId",
                table: "UploadedImage",
                column: "UserId",
                principalTable: "AspNetUsers",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);
        }
    }
}
