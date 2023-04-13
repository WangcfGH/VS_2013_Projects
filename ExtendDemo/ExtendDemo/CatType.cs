using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExtendDemo
{
    class CatType : Animal
    {
        private int ears;

        public int Ears
        {
            get { return ears; }
            set { ears = value; }
        }

        public virtual void Run()
        {
            Console.WriteLine("弓身下蹲，准备奔跑：");
        }

        public void BornType()
        {
            Console.WriteLine("我是胎生");
        }
    }
}
