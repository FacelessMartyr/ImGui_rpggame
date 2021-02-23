#pragma once
#ifndef FOOD_H
#define FOOD_H
#include "Item.h"
class Game_Food :public Game_Item
{
private:
	int base_heal;
	int nutritious;
	enum FoodCondition{Ordinary=1,Wellmade=2,};
public:
	Game_Food():Game_Item()
	{
		base_heal = 2;
		nutritious = 2;
	}
	Game_Food(int n_item_id, int n_cost,int n_rarity,int n_item_type,int  n_item_lvl,std::string n_item_name,int n_base_heal, int n_nutritious,int n_item_condition):Game_Item(n_item_id, n_cost, n_rarity, n_item_type, n_item_lvl, n_item_name, n_item_condition)
	{
		base_heal = n_base_heal;
		nutritious = n_nutritious; 
	}
	Game_Food(const Game_Food& a);
	Game_Food& operator=(const Game_Food& a);
	void eatFood()
	{
		;
	}
	
	void ShowInfo()
	{
		std::cout << "base_heal " << base_heal << std::endl;
		std::cout << "nutritious " << nutritious << "\n\n";
	}
	~Game_Food() {};
};
#endif 
