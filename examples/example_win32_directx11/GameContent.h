#pragma once
#ifndef GAME_CONTENT_H
#define GAME_CONTENT_H
#include "ad_data.h"
#include "r_libs.h"

class GameContent
{
private:
	const enum { items_pathlistSIZE = 5,npc_pathlistSIZE = 6, buf_SIZE = 160 };
	const std::string items_pathlist[items_pathlistSIZE] = {"items/loot/","items/weapons/","items/armour/","items/food/","items/flask/"};
    const std::string npc_pathlist[npc_pathlistSIZE] = { "npc/alchemist","npc/charmer","npc/farmer","npc/guardian","npc/merchant","npc/weaponsmith" };
	//Game_Weapon* weapon_data;
    
    friend class Game_Inventory;

public:
	
	GameContent()
	{
	
	};

    //Loading items
	void loadData_Weapons();//completed;
	void loadData_Armoury();//completed;
	void loadData_Food();//completed;
	void loadData_Flasks();//completed;
	void loadData_Loot();//completed;

    //
    const int contentWeapons_size() const { return ad_content::weapons_data.size(); }
    const int contentFood_size() const { return ad_content::food_data.size(); }
    const int contentArmour_size() const { return ad_content::armour_data.size(); }
    const int contentFlask_size() const { return ad_content::flask_data.size(); }
    const int contentLoot_size() const { return ad_content::loot_data.size(); }

    //Loading npc's
    
    void loadData_AlchemistNPC();
    void loadData_MerchantNPC();
    void loadData_GuardianNPC();
    void loadData_CharmerNPC();
    void loadData_WeaponsmithNPC();
    
	~GameContent()
	{
		
	}
    
};
#endif
