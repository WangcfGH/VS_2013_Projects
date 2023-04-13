using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PolymorphismDemo
{
    class TaskNpc : NPC
    {
        private string taskInfo;

        public TaskNpc(string taskInfo, string name, NpcType type)
            : base(name, type)
        {
            this.taskInfo = taskInfo;
        }

        public string TaskInfo
        {
            get { return taskInfo; }
            set { taskInfo = value; }
        }

        public override void Speak()
        {
            Console.WriteLine("任务Npc:{0},任务目标:{1}", base.Name, taskInfo);
        }
    }
}
