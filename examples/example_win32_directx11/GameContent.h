#pragma once
#ifndef GAME_CONTENT_H
#define GAME_CONTENT_H
#include "ad_data.h"
#include "r_libs.h"

class GameContent
{
private:
	const enum { pathlistSIZE = 5 };
	const std::string pathlist[pathlistSIZE] = {"items/loot/","items/weapons/","items/armour/","items/food/","items/flask/"};
	
	//Game_Weapon* weapon_data;
    
    friend class Game_Inventory;

public:
	
	GameContent()
	{
	
	};

	void loadData_Weapons();//completed;
	void loadData_Armoury();//completed;
	void loadData_Food();//completed;
	void loadData_Flasks();//completed;
	void loadData_Loot();//completed;

    int contentWeapons_size() const { return ad_content::weapons_data.size(); }
    int contentFood_size() const { return ad_content::food_data.size(); }
    int contentArmour_size() const { return ad_content::armour_data.size(); }
    int contentFlask_size() const { return ad_content::flask_data.size(); }
    int contentLoot_size() const { return ad_content::loot_data.size(); }
	
	~GameContent()
	{
		
	}
    
};
#endif
