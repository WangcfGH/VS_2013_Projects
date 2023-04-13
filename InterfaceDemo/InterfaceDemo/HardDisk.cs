using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InterfaceDemo
{
    class HardDisk : IUsb
    {
        private string content;

        public string Content
        {
            get { return content; }
            set { content = value; }
        }



        public string Type { get; set; }

        public string Read()
        {
            return content;
        }

        public void Write(string content)
        {
            this.content = content;
        }
    }
}
