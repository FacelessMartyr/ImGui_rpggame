#pragma once
#ifndef ITEM_H
#define ITEM_H
#include "r_libs.h"

class Game_Item
{
private:
	struct default_stats
	{
		int cost;
		int rarity;
		int item_type;
		int item_lvl;
		//default_stats() {};
	};
	enum ItemRarity{common=1,uncommon=2,rare=3,mythical=4,legendary=5,unique=6,immortal=7};
	enum ItemType{loot=0,weapon=1,armour=2,food=3,flask=4};
	default_stats stats;
	std::string item_name;
	int item_id;
	int item_condition;
	//std::string decription;
	
public:
	Game_Item(int n_item_id, int n_cost, int n_rarity, int n_item_type, int n_item_lvl, std::string n_item_name, int n_item_condition);
	Game_Item();
	~Game_Item() {};
	Game_Item(const Game_Item &a);
	Game_Item& operator=(const Game_Item& a);
	virtual void show_ItemInfo();

    int get_id()const { return item_id; };
    const default_stats& GetGameItemStats() { return stats; };
    const std::string& GetGameItemName() { return item_name; };
    const int GetGameItemCondition() { return item_condition; };
};
#endif
