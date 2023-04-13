using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C_Plus_Class_Type
{
    class Program
    {
        static void Main(string[] args)
        {
            Person p1 = new Person("Wcf");
            p1.SayHello();


            Person.Aims aim = new Person.Aims("学会游泳", 30);
            aim.AchieveAims();
    
            // 匿名类
            var vClass = new {name = "百度", url = "www.baidu.com"};
            Console.WriteLine("{0}:{1}", vClass.name, vClass.url);

            //装箱&&拆箱会增加性能开销，尽量减少
            int a = 10;
            Console.WriteLine(a);
            object b = a;           // 隐式自动装箱 值类型转为引用类型，栈空间->堆空间
            object c = (object)a;   // 显式自动装箱 值类型转为引用类型，栈空间->堆空间
            Console.WriteLine(b);
            Console.WriteLine(c);

            b = 30;
            a = (int)b;             // 显式手动拆箱 引用类型转值类型，堆空间->栈空间
            Console.WriteLine(a);
            
            Console.ReadKey();
        }
    }
}
