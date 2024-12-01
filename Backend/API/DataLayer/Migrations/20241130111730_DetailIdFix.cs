using Microsoft.EntityFrameworkCore.Migrations;
using Npgsql.EntityFrameworkCore.PostgreSQL.Metadata;

#nullable disable

namespace DataLayer.Migrations
{
    /// <inheritdoc />
    public partial class DetailIdFix : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "DetailEstimates");

            migrationBuilder.DropPrimaryKey(
                name: "PK_Estimates",
                table: "Estimates");

            migrationBuilder.DropColumn(
                name: "Id",
                table: "Estimates");

            migrationBuilder.AlterColumn<int>(
                name: "EstimatesID",
                table: "Estimates",
                type: "integer",
                nullable: false,
                oldClrType: typeof(int),
                oldType: "integer")
                .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn);

            migrationBuilder.AddPrimaryKey(
                name: "PK_Estimates",
                table: "Estimates",
                column: "EstimatesID");

            migrationBuilder.CreateTable(
                name: "Detail",
                columns: table => new
                {
                    InternalId = table.Column<int>(type: "integer", nullable: false),
                    EstimatesId = table.Column<int>(type: "integer", nullable: false),
                    SquareMillimeters = table.Column<long>(type: "bigint", nullable: false),
                    PaintRateMilliliters = table.Column<long>(type: "bigint", nullable: false),
                    Coast = table.Column<decimal>(type: "numeric", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Detail", x => new { x.EstimatesId, x.InternalId });
                    table.ForeignKey(
                        name: "FK_Detail_Estimates_EstimatesId",
                        column: x => x.EstimatesId,
                        principalTable: "Estimates",
                        principalColumn: "EstimatesID",
                        onDelete: ReferentialAction.Cascade);
                });
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "Detail");

            migrationBuilder.DropPrimaryKey(
                name: "PK_Estimates",
                table: "Estimates");

            migrationBuilder.AlterColumn<int>(
                name: "EstimatesID",
                table: "Estimates",
                type: "integer",
                nullable: false,
                oldClrType: typeof(int),
                oldType: "integer")
                .OldAnnotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn);

            migrationBuilder.AddColumn<int>(
                name: "Id",
                table: "Estimates",
                type: "integer",
                nullable: false,
                defaultValue: 0)
                .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn);

            migrationBuilder.AddPrimaryKey(
                name: "PK_Estimates",
                table: "Estimates",
                column: "Id");

            migrationBuilder.CreateTable(
                name: "DetailEstimates",
                columns: table => new
                {
                    DetailEstimatesId = table.Column<int>(type: "integer", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    Coast = table.Column<decimal>(type: "numeric", nullable: false),
                    EstimatesId = table.Column<int>(type: "integer", nullable: false),
                    InternalId = table.Column<int>(type: "integer", nullable: false),
                    PaintRateMilliliters = table.Column<long>(type: "bigint", nullable: false),
                    SquareMillimeters = table.Column<long>(type: "bigint", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_DetailEstimates", x => x.DetailEstimatesId);
                    table.ForeignKey(
                        name: "FK_DetailEstimates_Estimates_EstimatesId",
                        column: x => x.EstimatesId,
                        principalTable: "Estimates",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateIndex(
                name: "IX_DetailEstimates_EstimatesId",
                table: "DetailEstimates",
                column: "EstimatesId");
        }
    }
}
