using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PolymorphismDemo
{
    /// <summary>
    /// NPC类型
    /// </summary>
    public enum NpcType
    {
        Task,       // 任务类型
        Shop,       // 商贩类型
        BlackSmith  // 铁匠类型
    }

    abstract class NPC
    {
        private string name;
        private NpcType type;

        public NPC()
        {

        }

        public NPC(string name, NpcType type)
        {
            this.name = name;
            this.type = type;
        }

        public string Name
        {
            get { return name; }
            set { name = value; }
        }

        public NpcType Type
        {
            get { return type; }
            set { type = value; }
        }

        public virtual void SayHello()
        {
            Console.WriteLine("我是{0}", Name);
        }

        public abstract void Speak();
    }
}
