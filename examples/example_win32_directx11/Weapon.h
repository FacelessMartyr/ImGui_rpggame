#pragma once
#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"

class Game_Weapon :public Game_Item
{
private:
	struct default_weapon_stats
	{
		int physical_attack_dmg;
		int magical_attack_dmg = 0;
		int weapon_type;
	};
	enum WeaponType{none = 0, sword=1,katana=2};
    enum WeaponCondition {None = 0, Rusty = 1, Shabby = 2, Worn = 3, Dull = 4, Masterfull = 5, Heroic = 6, Imperial = 7 };
	default_weapon_stats specs;

    WeaponType weapon_type_enum;
    WeaponCondition weapon_condition_enum;
	
public:

    //Default constructor
	Game_Weapon():Game_Item()
	{
		specs.physical_attack_dmg = -1;
		specs.magical_attack_dmg = -1;
		specs.weapon_type = -1;
        weapon_condition_enum = WeaponCondition(WeaponCondition::None);
        weapon_type_enum = WeaponType(WeaponType::none);
	}

    //Constructor
	Game_Weapon(int n_item_id, int n_cost, int n_rarity, int n_item_type, int n_item_lvl, std::string n_item_name,
		int n_bphys_attack_dmg, int n_magical_attack_dmg, int n_weapon_type, int n_item_condition)
		:Game_Item(n_item_id, n_cost, n_rarity, n_item_type, n_item_lvl, n_item_name, n_item_condition)
	{
		specs.physical_attack_dmg = n_bphys_attack_dmg;
		specs.magical_attack_dmg = n_magical_attack_dmg;
		specs.weapon_type = n_weapon_type;
        weapon_condition_enum = WeaponCondition(n_item_condition);
        weapon_type_enum = WeaponType(n_weapon_type);

	}

    //Copying constructor
	Game_Weapon(const Game_Weapon & a);

    //Debug func
	virtual void ShowInfo();

    //Getters
    inline const WeaponType GetGameWeaponTypeEnum() const { return weapon_type_enum; }
    inline const WeaponCondition GetGameWeaponConditionEnum() const { return weapon_condition_enum; }
    inline const default_weapon_stats& GetGameWeaponStats() const { return specs; };

    inline const std::string GetGameWeaponConditionStr(WeaponCondition Type) const;
    inline const std::string GetGameWeaponTypeStr(WeaponType Type) const;

    //Output to ImGui
    void drawIntoImgui()const;

};
#endif
