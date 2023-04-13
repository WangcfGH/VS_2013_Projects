using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UsbDemo
{
    class HardDisk : Disk, IUsb
    {
        private string content;

        public HardDisk(string brand)
            : base(brand)
        {

        }

        public void Read()
        {
            Console.WriteLine("{0}正在读取数据：{1}", base.Brand, content);
        }

        public void Write(string content)
        {
            this.content += content;
            Console.WriteLine("{0}正在写入数据：{1}", base.Brand, content);
        }

        public override void Format()
        {
            base.Format();
            content = null;
            Console.WriteLine("格式化完毕...");
        }
    }
}
