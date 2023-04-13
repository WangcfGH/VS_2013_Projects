using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExtendDemo
{
    class BirdsType : Animal
    {
        private int wings;

        public int Wings
        {
            get { return wings; }
            set { wings = value; }
        }

        public void Fly()
        {
            Console.WriteLine("我会飞翔");
        }
    }
}
