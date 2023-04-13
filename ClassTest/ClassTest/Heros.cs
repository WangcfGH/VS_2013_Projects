using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassTest
{
    class Heros
    {
        private string heroName;
        private string heroInfo;
        private int attach;
        private int defence;
        private int speed;
        private string nickName;

        public Heros()
        {

        }

        public Heros(string heroName, string heroInfo, int attach, int defence, int speed, string nickName)
        {
            this.heroName = heroName;
            this.heroInfo = heroInfo;
            this.attach = attach;
            this.defence = defence;
            this.speed = speed;
            this.nickName = nickName;
        }

        public string HeroName
        {
            get { return heroName; }
            set { heroName = value; }
        }

        public string HeroInfo
        {
            get { return heroInfo; }
            set { heroInfo = value; }
        }

        public int Attach
        {
            get { return attach; }
            set { attach = value; }
        }

        public int Defence
        {
            get { return defence; }
            set { defence = value; }
        }

        public int Speed
        {
            get { return speed; }
            set { speed = value; }
        }

        public string NickName
        {
            get { return nickName; }
            set { nickName = value; }
        }

        public void Hello()
        {
            Console.WriteLine("我是{0}，我的简介：{1}，我的攻击值是{2}，我的防御值是{3}，我的速度是{4}，我的昵称是{5}",
                HeroName, HeroInfo, Attach, Defence, Speed, NickName);
        }
    }
}
