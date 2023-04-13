using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UsbDemo
{
    class Computer
    {
        private string brand;

        public IUsb usb1;
        public IUsb usb2;

        public string Brand
        {
            get { return brand; }
            set { brand = value; }
        }

        public Computer(string brand)
        {
            this.brand = brand;
        }

        public void Start()
        {
            Console.WriteLine("{0}正在开机中...", brand);
        }

        public void ShutDown()
        {
            Console.WriteLine("{0}正在关机中...", brand);
        }
    }
}
