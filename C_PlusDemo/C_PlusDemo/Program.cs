using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C_PlusDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("参数个数：{0} 参数：{1} 参数2：{2}", 2, "wcf", "fm");

            int[] intArray = new int[] { 1, 2, 3, 4, 5 };
            double[] dArray = new double[] { 0.0, 0.2, 0.3, 0.4, 0.5 };

            foreach (var item in intArray)
            {
                Console.WriteLine(item);
            }

            Console.WriteLine();

            foreach (var item in dArray)
            {
                Console.WriteLine(item);
            }
            
            Console.WriteLine();
            Console.WriteLine("--------------------------");
            int[,] intArry2 = new int[3,3];
            intArry2[0, 0] = 1;
            intArry2[0, 1] = 2;
            intArry2[0, 2] = 3;

            intArry2[1, 0] = 11;
            intArry2[1, 1] = 22;
            intArry2[1, 2] = 33;

            intArry2[2, 0] = 111;
            intArry2[2, 1] = 222;
            intArry2[2, 2] = 333;

            int[,] intArry3 = new int[4, 3] { { 1111, 2222, 3333 }, { 11111, 22222, 33333 }, { 111111, 222222, 333333 }, { 1111111, 2222222, 3333333 } };

            Console.WriteLine("length(0):{0}    length(1):{1}", intArry3.GetLength(0), intArry3.GetLength(1));
            for (int i = 0; i < intArry3.GetLength(0); i++)
            {
                for (int j = 0; j < intArry3.GetLength(1); j++)
                {
                    Console.Write(intArry3[i, j] + "\t");
                }
                Console.WriteLine();
            }

            Console.WriteLine(intArry2[0,1]);
            Console.WriteLine();
            Console.WriteLine("--------------------------");

            int[,] gameMaps = new int[10, 10] { 
            { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
            { 1, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
            { 1, 0, 0, 1, 0, 0, 0, 0, 0, 1 },
            { 1, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
            { 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
            { 1, 0, 0, 0, 0, 0, 1, 0, 0, 1 },
            { 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
            { 1, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
            { 1, 0, 0, 1, 0, 0, 0, 0, 0, 1 },
            { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
            };

            for (int i = 0; i < gameMaps.GetLength(0); i++)
            {
                for (int j = 0; j < gameMaps.GetLength(1); j++)
                {
                    if (gameMaps[i,j] == 1)
                    {
                        Console.Write("■");    
                    }
                    else
                    {
                        Console.Write("□");
                    }
                }
                Console.WriteLine();
            }
            Console.WriteLine();
            Console.WriteLine("--------------------------");

            string name = "WangChangFa";
            Console.WriteLine(name.Replace("a", "z"));

            string strFirst = "Wangcf";
            string strSecond = "Programmer";
            Console.WriteLine("strFirst:" + strFirst + "    strSecond:" + strSecond);
            Swap(ref strFirst, ref strSecond);
            Console.WriteLine("strFirst:" + strFirst + "    strSecond:" + strSecond);
            Console.ReadKey();
        }

        static void Swap(ref string s1, ref string s2)
        {
            string sTemp = s1;
            s1 = s2;
            s2 = sTemp;
            Console.WriteLine("s1:" + s1 + "  s2:" + s2);
        }
    }
}
