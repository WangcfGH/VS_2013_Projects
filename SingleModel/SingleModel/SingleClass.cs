using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SingleModel
{
    class SingleClass
    {
        // 定义一个静态且私有的该类字段
        private static SingleClass instance;

        // 定义一个私有的无参构造函数
        private SingleClass() { }

        // 定义一个静态且公开的实例化函数
        public static SingleClass Instance()
        {
            if (instance == null)
            {
                instance = new SingleClass();
            }

            return instance;
        }

        public void Hello()
        {
            Console.WriteLine("Hello");
        }
    }
}
