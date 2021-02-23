#pragma once
#ifndef FLASK_H
#define FLASK_H
#include "Item.h"
class Game_Flask:public Game_Item
{
private:
	enum FlaskCondition{};
	enum HealType{Life = 1, Mana = 2};
	int heal_type;
	int healing;
	int charges;
public:
	Game_Flask(int n_item_id, int n_cost, int n_rarity, int n_item_type,
		int n_item_lvl, std::string n_item_name,
		int n_item_condition,int n_healing, int n_charges,
		int n_heal_type):Game_Item(n_item_id, n_cost, n_rarity, n_item_type, n_item_lvl, n_item_name, n_item_condition)
	{
		heal_type = n_heal_type;
		healing = n_healing;
		charges = n_charges;
	}
	Game_Flask(const Game_Flask& a);
	Game_Flask& operator=(const Game_Flask& a);
	~Game_Flask()
	{
		;
	}
	
};

#endif
