#pragma once
#ifndef LOOT_H
#define LOOT_H
#include "Item.h"
class Game_Loot:public Game_Item
{
private:
	enum LootType{none = 0, MobDrop = 1, Ore = 2};
public:
    //Constructor
	Game_Loot(int n_item_id, int n_cost, int n_rarity, int n_item_type, int n_item_lvl, std::string n_item_name, int n_item_condition):Game_Item(n_item_id, n_cost, n_rarity, n_item_type, n_item_lvl, n_item_name, n_item_condition)
	{
		;
	}

    //Copying constructor
	Game_Loot(const Game_Loot& a):Game_Item(a)
	{
        ;
	}

    //Destructor
	~Game_Loot() {};

    //Output in ImGui
    void drawIntoImgui()const {};
};
#endif 
