using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PolymorphismDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            NPC tNpc = new TaskNpc("每日登陆领取福利", "登陆任务", NpcType.Task);
            if (tNpc is TaskNpc)
            {
                Console.WriteLine("他是任务Npc");
                tNpc.Speak();
            }
            else
            {
                Console.WriteLine("他不是任务Npc");
                tNpc.Speak();
            }

            Console.WriteLine("-------------------");

            NPC sNpc = new ShopNpc("喜羊羊", "灰太狼", NpcType.Shop);
            sNpc.Speak();

            Console.WriteLine("------------------");
            NPC bNpc = new BlackSmithNpc("破冰利剑", "修剑师", NpcType.BlackSmith);
            bNpc.Speak();

            Console.WriteLine("------------------");
            FuLei f = new ZhiLei();
            f.Hello();
            ZhiLei z = (ZhiLei)f;
            z.Hello();

            Console.ReadKey();
        }
    }
}
