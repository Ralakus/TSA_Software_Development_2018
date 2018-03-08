using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PrimeNumberGenerator
{
    class Program
    {
        static void Main(string[] args)
        {

            ulong GenTo = 0;
            ulong MinPrime = 0;

            Console.Write("Enter the amount to generate: ");

            bool Proceed = false;
            while (!Proceed)
            {
                try
                {
                    GenTo = ulong.Parse(Console.ReadLine());
                    Proceed = true;
                }
                catch
                {
                    Console.WriteLine("Enter an integer");
                }
            }

            Console.Write("Enter a minimium prime: ");

            Proceed = false;
            while (!Proceed)
            {
                try
                {
                    MinPrime = ulong.Parse(Console.ReadLine());
                    if (MinPrime >= GenTo)
                    {
                        Console.WriteLine("Minimium prime must be below Generate To");
                    }
                    else
                    {
                        Proceed = true;
                    }
                }
                catch
                {
                    Console.WriteLine("Enter an integer");
                }
            }

            Console.WriteLine("Generating...");
            List<bool> Primes = new List<bool>();

            for (ulong i = 0; i < GenTo; i++)
            {
                Primes.Add(false);
            }
            for (ulong i = 2; i < GenTo; i++)
            {
                if (!Primes[(int)i])
                {
                    for (ulong r = i + i; r < GenTo; r += i)
                    {
                        Primes[(int)r] = true;
                    }
                }
            }

            Console.WriteLine("Writing to file...");
            using (System.IO.StreamWriter Output =
            new System.IO.StreamWriter("GeneratedPrimesTo" + GenTo + ".txt"))
            {
                for (ulong i = 0; i < (ulong)Primes.Count; i++)
                {
                    if (!Primes[(int)i] && i >= MinPrime)
                    {
                        Output.WriteLine(i);
                    }
                }
                Output.Flush();
            }

            Console.WriteLine("Done");

        }
    }
}
