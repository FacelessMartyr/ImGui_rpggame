#include "Character.h"
//gaining xp and also levelingup character
int Character::character_gainxp()
{
	if ((cXP.Exp + cXP.base_reward) < cXP.ExpLVL)
	{
		cXP.Exp += cXP.base_reward;
	}
	else if ((cXP.Exp + cXP.base_reward) >= cXP.ExpLVL)
	{
		cXP.Exp += cXP.base_reward;
		cXP.Lvl++;
		cXP.ExpLVL = ((cXP.ExpLVL / 100) * 125) + cXP.pile;
		cXP.base_reward = ((cXP.ExpLVL - cXP.Exp) / 5);
	}
    return 0;
}
//adding character stats
void Character::character_addstats()
{
	int st_choice = 0;
	std::cout << statpoints_left << std::endl;
	if (statpoints_left > 0)
	{
		
		for (int i = 0; i < statpoints_left; )
		{
			if (std::cin >> st_choice)
			{
				switch (st_choice)
				{
				case 1:
					cStats.strength++;
					statpoints_left--;
					std::cout << statpoints_left << std::endl;
					show_stats();
					continue;
				case 2:
					cStats.agility++;
					statpoints_left--;
					std::cout << statpoints_left << std::endl;
					show_stats();
					continue;
				case 3:
					cStats.intelligence++;
					statpoints_left--;
					std::cout << statpoints_left << std::endl;
					show_stats();
					continue;
				default:
					break;
				}
				st_choice = 0;
			}
			else
				break;
		}
		std::cout << statpoints_left << std::endl;
	}
}


