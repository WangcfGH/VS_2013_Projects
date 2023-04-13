using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PolymorphismDemo
{
    class ShopNpc : NPC
    {
        private string item;

        public string Item
        {
            get { return item; }
            set { item = value; }
        }

        public ShopNpc(string item, string name, NpcType type)
            : base(name, type)
        {
            this.item = item;
        }

        public override void Speak()
        {
            Console.WriteLine("商贩Npc:{0},售卖商品:{1}", base.Name, item);
        }
    }
}
