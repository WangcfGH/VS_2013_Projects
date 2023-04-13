using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExtendDemo
{
    class Cat : CatType
    {
        public override void Run()
        {
            base.Run();

            Console.WriteLine("时速50，快速奔跑");
        }

        public void BuLaoSu()
        {
            Console.WriteLine("我会捕老鼠");
        }
    }
}
