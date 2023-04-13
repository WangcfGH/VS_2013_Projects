using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UsbDemo
{
    class Disk
    {
        private string brand;

        public string Brand
        {
            get { return brand; }
            set { brand = value; }
        }

        public Disk(string brand)
        {
            this.brand = brand;
        }

        public virtual void Format()
        {
            Console.WriteLine("{0}正在格式化...", brand);
        }
    }
}
