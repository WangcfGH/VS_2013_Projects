using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InterfaceDemo
{
    class BWMCar : Car
    {
        private int speed;

        public int Speed
        {
            get { return speed; }
            set { speed = value; }
        }

        public BWMCar(int speed, string brand)
            : base(brand)
        {
            this.speed = speed;
        }
        
        public override void Run()
        {
            base.Run();
            Console.WriteLine("时速：{0}", speed);
        }
    }
}
