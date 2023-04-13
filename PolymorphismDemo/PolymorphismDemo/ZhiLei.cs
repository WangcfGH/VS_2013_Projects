using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PolymorphismDemo
{
    class ZhiLei : FuLei
    {
        public void Hello()
        {
            Console.WriteLine("子类 Hello");
        }
    }
}
