using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassTest
{
    class LuoFei:Heros
    {
        public LuoFei()
        {

        }

        public LuoFei(string nickName)
            : base("洛菲", "我是洛菲，我是一名角色英雄", 75, 85, 50, nickName)
        {
        }

        public void GongJiXianJin()
        {
            Console.WriteLine("使用攻击陷阱");
        }

        public void BaoLiZhiDun()
        {
            Console.WriteLine("使用暴力之盾");
        }

        public void JiSuShanXian()
        {
            Console.WriteLine("使用急速闪现");
        }
    }
}
