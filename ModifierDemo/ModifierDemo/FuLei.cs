using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ModifierDemo
{
    class FuLei
    {
        protected string name;
        public static string address;

        public static string Address
        {
            get { return address;}
            set { address = value; }
        }
    }
}
