using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Net;
using System.Diagnostics;

using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace concurrent_with_WPF
{
    /// <summary>
    /// MainWindow.xaml の相互作用ロジック
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            Stopwatch sw = new Stopwatch();
            sw.Start();
            Loaded += Window_Loaded;
            sw.Stop();
            Debug.WriteLine($"{sw.Elapsed.Seconds} secnds");
        }

       private async void Window_Loaded(object sender,RoutedEventArgs e)
        {
            Uri url = new Uri("https://github.com/Microsoft/dotnet/blob/master/README.md");
            string body = await ReadFromUrlAsync(url);
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
    }
}
