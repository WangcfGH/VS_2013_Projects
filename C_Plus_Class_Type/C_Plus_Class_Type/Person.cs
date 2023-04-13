using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C_Plus_Class_Type
{
    /// <summary>
    /// 外部类
    /// </summary>
    class Person
    {
        /// <summary>
        /// 嵌套类
        /// </summary>
        public class Aims
        {
            private string aimsInfo;
            private int aimsTime;

            public string AimsInfo
            {
                get { return aimsInfo; }
                set { aimsInfo = value; }
            }

            public int AimsTime
            {
                get { return aimsTime; }
                set { aimsTime = value; }
            }

            public Aims(string info, int time)
            {
                this.aimsInfo = info;
                this.aimsTime = time;
            }

            public void AchieveAims()
            {
                Console.WriteLine("计划{0}天实现{1}目标", aimsTime, aimsInfo);
            }
        }

        private string name;

        public string Name
        {
            get { return name; }
            set { name = value; }
        }

        public Person(string name)
        {
            this.name = name;
        }

        public void SayHello()
        {
            Console.WriteLine("{0} Say Hello！！！", name);
        }
    }
}
