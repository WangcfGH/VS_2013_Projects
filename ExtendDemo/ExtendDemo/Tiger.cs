using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExtendDemo
{
    class Tiger : CatType
    {
        public override void Run()
        {
            base.Run();

            Console.WriteLine("时速100，飞速奔跑");
        }
    }
}
