using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Aidle
{
    class Program
    {
        static void Main(string[] args)
        {
            List<string> input = Console.ReadLine().Split(' ').ToList();
            int members = int.Parse(input[0]);
            int livecount = int.Parse(input[1]);
            List<List<int>> lives = new List<List<int>>();
            Enumerable.Range(1, livecount).ToList().ForEach((i) => {
                List<int> a;
                a = Console.ReadLine().Split(' ').Select<string,int>((e2) => {  return int.Parse(e2); }).ToList();
                lives.Add(a);
            });
            List<int> judge = new List<int>();
            lives.ToList().ForEach((e) => {
                judge.Add(e.Aggregate((e1,i1) => e1 + i1));
            });
            int result = 0;
            judge.ForEach((e) => {
                if (e >= 0)
                    result += e;
            });
            Console.WriteLine(result);
            Console.Read();
        }
    }
}
