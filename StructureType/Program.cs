using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StructureType
{
    public struct Koeficient
    {
        public int a, b;
    }

   static class LinearEquation
    {
        static Koeficient Koef; 
        static void Parse(string text)
        {

            string[] split = text.Split(",".ToCharArray());
            if (split.Length != 2)
                split = text.Split(" ".ToCharArray());
            if (split.Length != 2)
                throw new FormatException();
            try
            {

                Koef.a = int.Parse(split[0]);
                Koef.b = int.Parse(split[1]);
            }
            catch (FormatException)
            {
                throw new FormatException();
            }


        }



    }




    class Program
    {
        static void Main(string[] args)
        {

            Console.WriteLine("\n Please, give me two coefficients of linear equation a and b. \n Format: \"int32, int32\".");
            string line = Console.ReadLine();
            Coefficient k = new Coefficient();
            try
            {
                LinearEquation.Parse(line, ref k.a, ref k.b);
                Console.WriteLine(k.a + "   " + k.b);
                
            }
            catch (FormatException e)
            {
                Console.WriteLine("The catch is: \"{0}\"", e.Message);
                
            }
            finally
            {
                Console.WriteLine("By!");
            }


        }
    }
}
