using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InterfaceDemo
{
    interface IUsb
    {
        string Type { get; set; }

        string Read();

        void Write(string content);
    }
}
