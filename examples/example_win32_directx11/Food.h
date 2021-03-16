#pragma once
#ifndef FOOD_H
#define FOOD_H
#include "Item.h"
class Game_Food :public Game_Item
{
private:
	int base_heal;
	int nutritious;
	enum FoodCondition{none = 0, Ordinary=1,Wellmade=2,};

    FoodCondition food_condition_enum;
public:
    //Default constructor
	Game_Food():Game_Item()
	{
		base_heal = 2;
		nutritious = 2;
        food_condition_enum =FoodCondition(none);
	}

    //Constructor
	Game_Food(int n_item_id, int n_cost,int n_rarity,int n_item_type,int  n_item_lvl,std::string n_item_name,int n_base_heal, int n_nutritious,int n_item_condition):Game_Item(n_item_id, n_cost, n_rarity, n_item_type, n_item_lvl, n_item_name, n_item_condition)
	{
		base_heal = n_base_heal;
		nutritious = n_nutritious;
        food_condition_enum = FoodCondition(n_item_condition);
	}

    //Copying constructor
	Game_Food(const Game_Food& a);

    //Assignment operator
	Game_Food& operator=(const Game_Food& a);

    ~Game_Food() {};

    //Debug func
	void ShowInfo()
	{
		std::cout << "base_heal " << base_heal << std::endl;
		std::cout << "nutritious " << nutritious << "\n\n";
	}

    //Getters
    inline const FoodCondition GetGameFoodConditionEnum() const { return food_condition_enum; }
    inline const int GetGameFoodBase_Heal() const { return base_heal; }
    inline const int GetGameFoodNutritious() const { return nutritious; }

    inline const std::string GetGameFoodConditionStr(FoodCondition Type) const;

    //Output to ImGui
    void drawIntoImgui() const;

};
#endif 
