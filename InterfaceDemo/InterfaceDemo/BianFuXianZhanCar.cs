using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InterfaceDemo
{
    class BianFuXianZhanCar : Car, IFly
    {
        private int speedSound;

        public int SpeedSound
        {
            get { return speedSound; }
            set { speedSound = value; }
        }

        public BianFuXianZhanCar(int speedSound, string brand)
            : base(brand)
        {
            this.speedSound = speedSound;
        }

        public override void Run()
        {
            base.Run();
            Console.WriteLine("音速：{0}%", speedSound);
        }

        public void Fly()
        {
            Console.WriteLine("{0}起飞", base.Brand);
        }

        public void Shooting()
        {
            throw new NotImplementedException();
        }
    }
}
