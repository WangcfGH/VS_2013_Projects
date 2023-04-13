using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SingleModel
{
    class Program
    {
        static void Main(string[] args)
        {
            SingleClass s1 = SingleClass.Instance();
            s1.Hello();

            Console.ReadKey();
        }
    }
}
