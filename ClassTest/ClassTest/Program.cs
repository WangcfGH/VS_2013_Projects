using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassTest
{
    class Program
    {
        static void Main(string[] args)
        {
            /*
            Person p1 = new Person("王常法", 18, GENDER.BOY, "浙江杭州");

            p1.Hello();
            p1.Eat();
            p1.Sleep();
            p1.Work();

            Person p2 = p1;
            p2.Hello();
            p2.Name = "王常波";
            p2.Hello();
            p1.Hello();
            */

            AiLuoKe alk = new AiLuoKe("Monky");
            alk.Hello();
            alk.PiJingZhanJi();
            alk.FeiMaoTui();
            alk.WuYingZhang();

            Console.WriteLine();
            ShaWa sw = new ShaWa("玫瑰");
            sw.Hello();
            sw.BoBaWuDi();
            sw.GuiMeiHou();
            sw.QiSheShenGong();

            Console.WriteLine();
            TaiTan tt = new TaiTan("胖子");
            tt.Hello();
            tt.ZhongLiZhiChui();
            tt.ChongJiBo();
            tt.QianJingKun();


            Console.WriteLine();
            LuoFei lf = new LuoFei("小黑");
            lf.Hello();
            lf.GongJiXianJin();
            lf.BaoLiZhiDun();
            lf.JiSuShanXian();

            Console.ReadKey();
        }
    }
}
