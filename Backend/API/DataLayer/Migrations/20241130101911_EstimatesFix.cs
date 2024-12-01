using Microsoft.EntityFrameworkCore.Migrations;
using Npgsql.EntityFrameworkCore.PostgreSQL.Metadata;

#nullable disable

namespace DataLayer.Migrations
{
    /// <inheritdoc />
    public partial class EstimatesFix : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropColumn(
                name: "Payload",
                table: "Estimates");

            migrationBuilder.AddColumn<int>(
                name: "PayloadId",
                table: "Estimates",
                type: "integer",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.CreateTable(
                name: "EstimatesPayload",
                columns: table => new
                {
                    Id = table.Column<int>(type: "integer", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    StandardSizeMillimeters = table.Column<long>(type: "bigint", nullable: false),
                    TorchWidthMillimeters = table.Column<long>(type: "bigint", nullable: false),
                    TorchTakeoffMillimeters = table.Column<long>(type: "bigint", nullable: false),
                    CoastPerLiter = table.Column<long>(type: "bigint", nullable: false),
                    PaintMillilitersPerSquareMeter = table.Column<long>(type: "bigint", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_EstimatesPayload", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "DetailInfo",
                columns: table => new
                {
                    Id = table.Column<int>(type: "integer", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    SquareMillimeters = table.Column<long>(type: "bigint", nullable: false),
                    PaintRateMilliliters = table.Column<long>(type: "bigint", nullable: false),
                    Coast = table.Column<decimal>(type: "numeric", nullable: false),
                    EstimatesPayloadId = table.Column<int>(type: "integer", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_DetailInfo", x => x.Id);
                    table.ForeignKey(
                        name: "FK_DetailInfo_EstimatesPayload_EstimatesPayloadId",
                        column: x => x.EstimatesPayloadId,
                        principalTable: "EstimatesPayload",
                        principalColumn: "Id");
                });

            migrationBuilder.CreateIndex(
                name: "IX_Estimates_PayloadId",
                table: "Estimates",
                column: "PayloadId");

            migrationBuilder.CreateIndex(
                name: "IX_DetailInfo_EstimatesPayloadId",
                table: "DetailInfo",
                column: "EstimatesPayloadId");

            migrationBuilder.AddForeignKey(
                name: "FK_Estimates_EstimatesPayload_PayloadId",
                table: "Estimates",
                column: "PayloadId",
                principalTable: "EstimatesPayload",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_Estimates_EstimatesPayload_PayloadId",
                table: "Estimates");

            migrationBuilder.DropTable(
                name: "DetailInfo");

            migrationBuilder.DropTable(
                name: "EstimatesPayload");

            migrationBuilder.DropIndex(
                name: "IX_Estimates_PayloadId",
                table: "Estimates");

            migrationBuilder.DropColumn(
                name: "PayloadId",
                table: "Estimates");

            migrationBuilder.AddColumn<string>(
                name: "Payload",
                table: "Estimates",
                type: "text",
                nullable: false,
                defaultValue: "");
        }
    }
}
