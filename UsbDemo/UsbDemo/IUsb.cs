using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UsbDemo
{
    interface IUsb
    {
        void Read();
        void Write(string content);
    }
}
