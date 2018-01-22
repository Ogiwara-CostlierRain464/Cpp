using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ReversPolishNatation
{
    class Program
    {
        static void Main(string[] args)
        {
            ReversPolishNatation.Perse("32 45 + 58 545");
        }
    }

    static class ReversPolishNatation
    {
        static int position = 0;

        static Stack<string> stack = new Stack<string>();

        public static void Perse(string exp)
        {
            //Ex. 23 34 + 87
            while (position < exp.Length)
            {
                string cash ="";
                while (exp[position] != ' ')
                {
                    cash += exp[position];
                    position += 1;
                }
                stack.Push(cash);
            }
            stack.ToList<string>().ForEach((e)=> {
                Console.WriteLine($"{e};");
            });
        }
    }
}
