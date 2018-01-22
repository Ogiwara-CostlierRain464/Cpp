using System;
using System.Threading.Tasks;
using System.Text;
using System.IO;
using System.Net;
using System.Diagnostics;

namespace concurrent
{
    class Program
    {
        static void Main(string[] args)
        {
            Stopwatch sw = new Stopwatch();
            sw.Start();

            Task t = DownloadAsync();
            t.Wait();

            sw.Stop();
            Console.WriteLine($"{sw.Elapsed.Seconds}seconds");
            Console.Read();
        }

        public static async Task<string> ReadFromUrlAsync(Uri url)
        {
            using (WebClient webClient = new WebClient())
            {
                using (Stream stream = await webClient.OpenReadTaskAsync(url))
                {
                    TextReader tr = new StreamReader(stream, Encoding.UTF8, true);
                    string body = await tr.ReadToEndAsync();
                    return body;
                }
            }
        }

        public static async Task DownloadAsync()
        {
            Uri url = new Uri("https://github.com/Microsoft/dotnet/blob/master/README.md");
            string body = await ReadFromUrlAsync(url);
            //Console.WriteLine(body);
        }
    }
}
