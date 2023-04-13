using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestDelegate
{
    class TempClass
    {
        public void tempFunc(string m)
        {
            Console.WriteLine("object methode tempFunc");
        }
    }

    class Program
    {
        delegate void MyDelegate(string message);
        MyDelegate m_myDelegate;
        static void Write(string message)
        {
            Console.WriteLine("{0} this is using named method", message);
        }

        void transDelegateFuc(MyDelegate myDelegate, string m)
        {
            m_myDelegate += onclick;
            m_myDelegate += myDelegate;
        }

        void onclick(string m)
        {
            Console.WriteLine("{0} onclick", m);
        }

        void addClick()
        {
            transDelegateFuc(onclick, "Test");
        }

        static void Main(string[] args)
        {
            TempClass tmpClass = new TempClass();
            Program tempPro = new Program();

           //1.一般的调用命名方法
　　　　    MyDelegate mydelegate = Write;
 
　　　　    //2.委托
　　　　    mydelegate += delegate(string m)
　　　　    {
　　　　　　    Console.WriteLine("{0} this is using delegate",m);
　　　　    };
 
　　　　    //3.拉姆达
            mydelegate += (string m) =>
            {
                Console.WriteLine("{0} this is using  lambda", m);
            };

            //4.实例对象的方法
            mydelegate += tmpClass.tempFunc;
 
 　　　　   mydelegate("C#");

            tempPro.addClick();
            Console.ReadLine();
        }
    }
}
