using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExtendDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            Tiger t = new Tiger();
            t.Leg = 4;
            t.Ears = 2;
            t.Sleep();
            t.Cry();
            t.BornType();
            t.Run();

            Console.WriteLine("----------------------------");

            Cat c = new Cat();
            c.Leg = 4;
            c.Ears = 2;
            c.Sleep();
            c.Cry();
            c.BornType();
            c.BuLaoSu();
            c.Run();

            Console.WriteLine("----------------------------");
            Owl o = new Owl();
            o.Leg = 2;
            o.Wings = 2;
            o.Sleep();
            o.Fly();

            Console.WriteLine("----------------------------");
            Swallow s = new Swallow();
            s.Leg = 2;
            s.Wings = 2;
            s.Cry();
            s.Fly();
            s.WangNanFei();

            Console.ReadKey();
        }
    }
}
