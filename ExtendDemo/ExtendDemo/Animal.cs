using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExtendDemo
{
    class Animal
    {
        private int leg;

        public int Leg
        {
            get { return leg; }
            set { leg = value; }
        }

        public void Sleep()
        {
            Console.WriteLine("我要睡觉");
        }

        public void Cry()
        {
            Console.WriteLine("我会叫");
        }

        public void Eat()
        {
            Console.WriteLine("我要进食");
        }
    }
}
