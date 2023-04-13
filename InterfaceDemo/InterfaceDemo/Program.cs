using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InterfaceDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            /*
            BWMCar bwmCar1 = new BWMCar(150, "宝马750");
            bwmCar1.Run();

            BWMCar bwmCar2 = new BWMCar(120, "宝马740");
            bwmCar2.Run();

            BianFuXianZhanCar bfxzCar = new BianFuXianZhanCar(95, "蝙蝠侠战车1");
            bfxzCar.Run();
            bfxzCar.Fly();
            */

            UDisk Ud = new UDisk();
            Ud.Type = "U盘";
            Ud.Write("中国崛起");
            Console.WriteLine(Ud.Type + "读取数据：" + Ud.Read());

            HardDisk Hd = new HardDisk();
            Hd.Type = "硬盘";
            Hd.Write("年少有为");
            Console.WriteLine(Hd.Type + "读取数据：" + Hd.Read());

            Console.ReadKey();
        }
    }
}
