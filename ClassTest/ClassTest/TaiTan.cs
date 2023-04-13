using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassTest
{
    class TaiTan:Heros
    {
        public TaiTan()
        {

        }

        public TaiTan(string nickName)
            : base("泰坦", "我是泰坦，我是一名角色英雄", 75, 85, 50, nickName)
        {
        }

        public void ZhongLiZhiChui()
        {
            Console.WriteLine("使用重力之锤");
        }

        public void ChongJiBo()
        {
            Console.WriteLine("使用冲击波");
        }

        public void QianJingKun()
        {
            Console.WriteLine("使用千斤捆");
        }
    }
}
