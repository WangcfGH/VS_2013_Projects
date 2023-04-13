using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InterfaceDemo
{
    class Car
    {
        private string brand;

        public string Brand
        {
            get { return brand; }
            set { brand = value; }
        }

        public Car(string brand)
        {
            this.brand = brand;
        }

        public virtual void Run()
        {
            Console.WriteLine("{0}在奔跑...", brand);
        }
    }
}
