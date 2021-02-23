#pragma once
#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"

class Game_Weapon :public Game_Item
{
private:
	struct default_weapon_stats
	{
		int bphys_attack_dmg;
		int magical_attack_dmg = 0;
		int weapon_type;
	};
	enum WeaponType{sword=1,katana=2};
	default_weapon_stats specs;
	enum WeaponCondition{Rusty=1,Shabby=2,Worn=3,Dull=4,Masterfull=5,Heroic=6,Imperial=7};
public:
	Game_Weapon():Game_Item()
	{
		specs.bphys_attack_dmg = -1;
		specs.magical_attack_dmg = -1;
		specs.weapon_type = -1;
	}
	Game_Weapon(int n_item_id, int n_cost, int n_rarity, int n_item_type, int n_item_lvl, std::string n_item_name,
		int n_bphys_attack_dmg, int n_magical_attack_dmg, int n_weapon_type, int n_item_condition)
		:Game_Item(n_item_id, n_cost, n_rarity, n_item_type, n_item_lvl, n_item_name, n_item_condition)
	{
		specs.bphys_attack_dmg = n_bphys_attack_dmg;
		specs.magical_attack_dmg = n_magical_attack_dmg;
		specs.weapon_type = n_weapon_type;
	}
	Game_Weapon(const Game_Weapon & a);
	virtual void ShowInfo();

    const default_weapon_stats& GetGameWeaponSpecs() { return specs; };

};
#endif
