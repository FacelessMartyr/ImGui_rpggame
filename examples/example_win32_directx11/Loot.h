#pragma once
#ifndef LOOT_H
#define LOOT_H
#include "Item.h"
class Game_Loot:public Game_Item
{
private:
	
public:
	Game_Loot(int n_item_id, int n_cost, int n_rarity, int n_item_type, int n_item_lvl, std::string n_item_name, int n_item_condition):Game_Item(n_item_id, n_cost, n_rarity, n_item_type, n_item_lvl, n_item_name, n_item_condition)
	{
		;
	}
	Game_Loot(const Game_Loot& a):Game_Item(a)
	{

	};
	~Game_Loot() {};
};
#endif 
