using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ComplexNumber
{

    class Complex
    {
        private double a;
        private double b;

        public double B
        {
            get { return b; }
            set { b = value; }
        }
        public double A
        {
            get { return a; }
            set { a = value; }
        }

        public Complex(double a=1, double b=1)
        {
            this.a = a;
            this.b = b;
        }

        public override string ToString()
        {
            if (b<0)
            {
                return $"{a}{b}i";
            }
            else
            {
                return $"{a}+{b}i";
            }
            
        }

        // протилежне комплексне число
        public static Complex operator -(Complex c)
        {
            return new Complex(-c.a, -c.b);
        }

        public static Complex operator ~(Complex c)
        {
            return new Complex(c.a, -c.b);
        }        public static double operator !(Complex c)
        {
            return Math.Sqrt(c.a * c.a + c.b * c.b);
        }


        public static Complex operator ++(Complex c)
        {
            return new Complex(++c.a, ++c.b);
        }


        public static bool operator true(Complex c)
        {
            return c.b == 0;
        }


        public static bool operator false(Complex c)
        {
            return c.b != 0;
        }

        public static Complex operator +(Complex c1,Complex c2)
        {
            return
            new Complex(c1.a + c2.a, c1.b + c2.b);
        }

        public static Complex operator +(Complex c,double d)
        {
            return new Complex(c.a + d, c.b);
        }


        public static Complex operator +(int i,Complex c)
        {
            return new Complex(c.a + i, c.b);
        }

        public static Complex operator *(Complex c1, Complex c2)
        {
            return new Complex(c1.a * c2.a - c1.b * c2.b, c1.b * c2.a + c1.a * c2.b);
        }

        public static Complex operator /(Complex c1, Complex c2)
        {
            return new Complex((c1.a * c2.a + c1.b * c2.b) / (c2.a * c2.b + c2.b * c2.b), (c1.b * c2.a - c1.a * c2.b) / (c2.a * c2.a + c2.b * c2.b));
        }


        public static Complex operator *(double a, Complex c)
        {
            return new Complex(a * c.a, a * c.b);
        }

        public static Complex operator *(Complex c, double a)
        {
            return a * c;
        }
        
        public static bool operator ==(Complex c1,Complex c2)
        {
            return c1.a == c2.a && c1.b == c2.b;
        }


        public static bool operator !=(Complex c1,Complex c2)
        {
            return !(c1 == c2);
        }

        public static implicit operator Complex(double d)
        {
            return new Complex(d, 0);
        }
        public static explicit operator double(Complex c)
        {
            return c.a;
        }



    }





    class Program
    {
        static void Main(string[] args)
        {

            Complex a = new Complex(5, 3);
            Complex b = new Complex();

            b = -b;
            Console.WriteLine(a);
            Console.WriteLine(b);

        }
    }
}
