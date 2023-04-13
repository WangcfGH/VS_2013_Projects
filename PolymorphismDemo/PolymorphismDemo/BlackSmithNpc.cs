using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PolymorphismDemo
{
    class BlackSmithNpc : NPC
    {
        private string weapon;

        public string Weapon
        {
            get { return weapon; }
            set { weapon = value; }
        }

        public BlackSmithNpc(string weapon, string name, NpcType type)
            : base(name, type)
        {
            this.weapon = weapon;
        }

        public override void Speak()
        {
            Console.WriteLine("铁匠Npc{0},修复兵器:{1}", base.Name, weapon);
        }
    }
}
