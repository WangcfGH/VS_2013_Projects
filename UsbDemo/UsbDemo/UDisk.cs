using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UsbDemo
{
    class UDisk : Disk, IUsb
    {
        /// <summary>
        /// U盘存储内容
        /// </summary>
        private string content;

        public UDisk(string brand)
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
