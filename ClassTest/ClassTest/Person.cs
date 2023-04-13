using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassTest
{
    public enum GENDER
    {
        BOY,
        GRIL
    }

    class Person
    {
        private string      name;     // 姓名
        private int         age;      // 年龄
        private GENDER      gender;   // 性别
        private string      address;  // 地址

        public Person()
        {

        }

        public Person(string name, int age, GENDER gender, string address)
        {
            this.name = name;
            this.age = age;
            this.gender = gender;
            this.address = address;
        }

        public string Name
        {
            get { return name; }
            set { name = value; }
        }

        public int Age
        {
            get { return age; }
            set { age = value; }
        }

        public GENDER Gender
        {
            get { return gender; }
            set { gender = value; }
        }

        public string Address
        {
            get { return address; }
            set { address = value; }
        }

        public void Hello()
        {
            Console.WriteLine("我的名字是{0}，我{1}岁了，我是{2}，我的地址是{3}。", name, age, gender, address);
        }

        public void Eat()
        {
            Console.WriteLine(Name + "吃饭");
        }

        public void Sleep()
        {
            Console.WriteLine(Name + "睡觉");
        }

        public void Work()
        {
            Console.WriteLine(Name + "工作");
        }

    }
}
