using Microsoft.Extensions.Configuration;
using Microsoft.VisualBasic.FileIO;
using ServiceLayer.Models;
using System.Diagnostics;

namespace ServiceLayer.Services.Concrete
{
    public class DetailsPaintingAreaService : IDetailsPaintingAreaService
    {
        private readonly string _scriptPath;
        private readonly string _pythonPath;

        public DetailsPaintingAreaService(IConfiguration configuration)
        {
            _scriptPath = configuration["ScriptPath"];
            _pythonPath = configuration["PythonPath"];
        }

        // здесь будет обращение к скрипту
        public IEnumerable<DetailPaintingArea> GetDetailPaintingAreas(DrawEstimatesInDto inDto, string outFilePath)
        {
            string outDir = Path.GetDirectoryName(outFilePath);
            int typeIndex = inDto.StandardDetail switch
            {
                StandardDetail.FrontDoor => 5,
                StandardDetail.Bonnet => 3,
                StandardDetail.TrunkLid => 1
            };
            // Аргументы, которые нужно передать в скрипт
            string arg1 = inDto.ImageFilePath;
            string arg2 = typeIndex.ToString();
            string arg3 = inDto.StandardSizeMillimeters.ToString();
            string arg4 = outDir;

            // Формируем аргументы
            string arguments = $"\"{_scriptPath}\" \"{arg1}\" {arg2} {arg3} \"{arg4}\"";

            // Настраиваем процесс
            ProcessStartInfo startInfo = new ProcessStartInfo
            {
                FileName = _pythonPath,
                Arguments = arguments,
                RedirectStandardOutput = true, // Перенаправление вывода
                RedirectStandardError = true,
                UseShellExecute = false, // Не использовать оболочку
                CreateNoWindow = true    // Без создания окна
            };

            try
            {
                using (Process process = Process.Start(startInfo))
                {
                    // Чтение вывода скрипта
                    string output = process.StandardOutput.ReadToEnd();
                    string error = process.StandardError.ReadToEnd();

                    process.WaitForExit();

                    Console.WriteLine("Output:");
                    Console.WriteLine(output);

                    if (!string.IsNullOrWhiteSpace(error))
                    {
                        Console.WriteLine("Error:");
                        Console.WriteLine(error);
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"An error occurred: {ex.Message}");
            }

            string filename = Path.GetFileNameWithoutExtension(inDto.ImageFilePath);
            string imagePath = Path.Combine(outDir, $"{filename}_segmented.jpg");
            string sizesPath = Path.Combine(outDir, $"{filename}_sizes.csv");
            File.Move(Path.Combine(Path.GetDirectoryName(outFilePath), imagePath), outFilePath);

            List<DetailPaintingArea> details = new List<DetailPaintingArea>();
            using (TextFieldParser parser = new TextFieldParser(sizesPath))
            {
                parser.TextFieldType = FieldType.Delimited;
                parser.SetDelimiters(",");
                string[] header = parser.ReadFields();
                while (!parser.EndOfData)
                {
                    //Processing row
                    string[] fields = parser.ReadFields();
                    details.Add(new DetailPaintingArea()
                    {
                        Id = int.Parse(fields[0]),
                        SquareMillimeters = uint.Parse(fields[1]),
                    });
                }
            }

            return details;
        }
    }
}
