using Microsoft.EntityFrameworkCore.Migrations;
using Npgsql.EntityFrameworkCore.PostgreSQL.Metadata;

#nullable disable

namespace DataLayer.Migrations
{
    /// <inheritdoc />
    public partial class DetailsFix : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_Estimates_EstimatesPayload_PayloadId",
                table: "Estimates");

            migrationBuilder.DropTable(
                name: "DetailInfo");

            migrationBuilder.DropTable(
                name: "EstimatesPayload");

            migrationBuilder.DropPrimaryKey(
                name: "PK_Estimates",
                table: "Estimates");

            migrationBuilder.DropIndex(
                name: "IX_Estimates_PayloadId",
                table: "Estimates");

            migrationBuilder.RenameColumn(
                name: "PayloadId",
                table: "Estimates",
                newName: "Id");

            migrationBuilder.AlterColumn<int>(
                name: "EstimatesID",
                table: "Estimates",
                type: "integer",
                nullable: false,
                oldClrType: typeof(int),
                oldType: "integer")
                .OldAnnotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn);

            migrationBuilder.AlterColumn<int>(
                name: "Id",
                table: "Estimates",
                type: "integer",
                nullable: false,
                oldClrType: typeof(int),
                oldType: "integer")
                .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn);

            migrationBuilder.AddColumn<long>(
                name: "CoastPerLiter",
                table: "Estimates",
                type: "bigint",
                nullable: false,
                defaultValue: 0L);

            migrationBuilder.AddColumn<long>(
                name: "PaintMillilitersPerSquareMeter",
                table: "Estimates",
                type: "bigint",
                nullable: false,
                defaultValue: 0L);

            migrationBuilder.AddColumn<long>(
                name: "StandardSizeMillimeters",
                table: "Estimates",
                type: "bigint",
                nullable: false,
                defaultValue: 0L);

            migrationBuilder.AddColumn<long>(
                name: "TorchTakeoffMillimeters",
                table: "Estimates",
                type: "bigint",
                nullable: false,
                defaultValue: 0L);

            migrationBuilder.AddColumn<long>(
                name: "TorchWidthMillimeters",
                table: "Estimates",
                type: "bigint",
                nullable: false,
                defaultValue: 0L);

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
                    InternalId = table.Column<int>(type: "integer", nullable: false),
                    SquareMillimeters = table.Column<long>(type: "bigint", nullable: false),
                    PaintRateMilliliters = table.Column<long>(type: "bigint", nullable: false),
                    Coast = table.Column<decimal>(type: "numeric", nullable: false),
                    EstimatesId = table.Column<int>(type: "integer", nullable: false)
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

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "DetailEstimates");

            migrationBuilder.DropPrimaryKey(
                name: "PK_Estimates",
                table: "Estimates");

            migrationBuilder.DropColumn(
                name: "CoastPerLiter",
                table: "Estimates");

            migrationBuilder.DropColumn(
                name: "PaintMillilitersPerSquareMeter",
                table: "Estimates");

            migrationBuilder.DropColumn(
                name: "StandardSizeMillimeters",
                table: "Estimates");

            migrationBuilder.DropColumn(
                name: "TorchTakeoffMillimeters",
                table: "Estimates");

            migrationBuilder.DropColumn(
                name: "TorchWidthMillimeters",
                table: "Estimates");

            migrationBuilder.RenameColumn(
                name: "Id",
                table: "Estimates",
                newName: "PayloadId");

            migrationBuilder.AlterColumn<int>(
                name: "EstimatesID",
                table: "Estimates",
                type: "integer",
                nullable: false,
                oldClrType: typeof(int),
                oldType: "integer")
                .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn);

            migrationBuilder.AlterColumn<int>(
                name: "PayloadId",
                table: "Estimates",
                type: "integer",
                nullable: false,
                oldClrType: typeof(int),
                oldType: "integer")
                .OldAnnotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn);

            migrationBuilder.AddPrimaryKey(
                name: "PK_Estimates",
                table: "Estimates",
                column: "EstimatesID");

            migrationBuilder.CreateTable(
                name: "EstimatesPayload",
                columns: table => new
                {
                    Id = table.Column<int>(type: "integer", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    CoastPerLiter = table.Column<long>(type: "bigint", nullable: false),
                    PaintMillilitersPerSquareMeter = table.Column<long>(type: "bigint", nullable: false),
                    StandardSizeMillimeters = table.Column<long>(type: "bigint", nullable: false),
                    TorchTakeoffMillimeters = table.Column<long>(type: "bigint", nullable: false),
                    TorchWidthMillimeters = table.Column<long>(type: "bigint", nullable: false)
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
                    Coast = table.Column<decimal>(type: "numeric", nullable: false),
                    EstimatesPayloadId = table.Column<int>(type: "integer", nullable: true),
                    PaintRateMilliliters = table.Column<long>(type: "bigint", nullable: false),
                    SquareMillimeters = table.Column<long>(type: "bigint", nullable: false)
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
    }
}
