using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UsbDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            //多态：在继承的前提下，实例出不同的子类对象，这些对象调用相同的方法，但是却有不同的行为，此为多态。
            UDisk uD = new UDisk("金斯顿32G");
            HardDisk hD = new HardDisk("三星500G");

            Computer c1 = new Computer("联想");
            c1.Start();

            Console.WriteLine();
            c1.usb1 = uD;
            c1.usb1.Write("中华崛起");
            c1.usb1.Write("我辈自强");
            c1.usb1.Read();

            Console.WriteLine();
            uD.Format();

            Console.WriteLine();
            c1.usb2 = hD;
            c1.usb2.Write("科技强国");
            c1.usb2.Write("自主自研");
            c1.usb2.Read();

            Console.WriteLine();
            hD.Format();

            Console.WriteLine();
            c1.ShutDown();
            Console.WriteLine();
            Console.WriteLine();
            Console.WriteLine();
            Console.WriteLine();

            Computer c2 = new Computer("戴尔");
            c2.Start();
            c2.ShutDown();

            Console.ReadKey();
        }
    }
}
