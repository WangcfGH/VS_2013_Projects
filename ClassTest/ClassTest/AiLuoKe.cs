using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassTest
{
    class AiLuoKe:Heros
    {
        public AiLuoKe()
        {

        }

        public AiLuoKe(string nickName)
            : base("埃洛克", "我是埃洛克，我是一名角色英雄", 80, 65, 40, nickName)
        {
        }

        public void PiJingZhanJi()
        {
            Console.WriteLine("使用披荆斩棘");
        }

        public void FeiMaoTui()
        {
            Console.WriteLine("使用飞毛腿");
        }

        public void WuYingZhang()
        {
            Console.WriteLine("使用无影掌");
        }
    }
}
