using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassTest
{
    class ShaWa:Heros
    {
        public ShaWa()
        {

        }

        public ShaWa(string nickName)
            : base("莎娃", "我是莎娃，我是一名角色英雄", 85, 55, 60, nickName)
        {
        }

        public void BoBaWuDi()
        {
            Console.WriteLine("使用波霸无敌");
        }

        public void GuiMeiHou()
        {
            Console.WriteLine("使用鬼魅吼");
        }

        public void QiSheShenGong()
        {
            Console.WriteLine("使用骑射神功");
        }
    }
}
