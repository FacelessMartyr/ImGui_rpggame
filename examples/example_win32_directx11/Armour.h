#pragma once
#ifndef ARMOUR_H
#define ARMOUR_H
#include "Item.h"
class Game_Armour:public Game_Item
{
private:
	struct default_armour_stats
	{
		enum armour_type { helmet = 1, chest = 2, leggins = 3, boots = 4 };
		int armour_type;
		int armour;
		int evasion;
	};
	enum ArmourCondition { Shabby = 1, Worn = 2, Sturdy = 3, Masterfull = 4,Superb = 5, Heroic = 6, Imperial = 7};
	default_armour_stats stats;
public:
	Game_Armour():Game_Item()
	{
		stats.armour_type = -1;
		stats.armour = -1;
		stats.evasion = -1;
	}
	Game_Armour(int n_item_id, int n_cost, int n_rarity, int n_item_type, int n_item_lvl, std::string n_item_name,int n_armour_type, int n_armour, int n_evasion,int n_item_condition);
	Game_Armour(const Game_Armour& a);
	Game_Armour& operator=(const Game_Armour& a);
	~Game_Armour() {};
};
#endif
