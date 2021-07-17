#pragma once
#ifndef ARMOUR_H
#define ARMOUR_H
#include "Item.h"
class Game_Armour:public Game_Item
{
private:
	struct default_armour_stats
	{
		
		int armour_type;
		int armour;
		int evasion;
	};
    enum ArmourType {none = 0, helmet = 1, chest = 2, leggins = 3, boots = 4 };
	enum ArmourCondition {None = 0, Shabby = 1, Worn = 2, Sturdy = 3, Masterfull = 4,Superb = 5, Heroic = 6, Imperial = 7};

    ArmourType armour_type_enum;
    ArmourCondition armour_condition_enum;
    
	default_armour_stats stats;
public:

    //Default constructor
	Game_Armour():Game_Item()
	{
		stats.armour_type = -1;
		stats.armour = -1;
		stats.evasion = -1;
        armour_type_enum = ArmourType(ArmourType::none);
        armour_condition_enum = ArmourCondition(ArmourCondition::None);
	}

    //Constructor
	Game_Armour(int n_item_id, int n_cost, int n_rarity, int n_item_type, int n_item_lvl, std::string n_item_name,int n_armour_type, int n_armour, int n_evasion,int n_item_condition, std::string n_description);

    //Copying constructor
    Game_Armour(const Game_Armour& a);

    //Assignment operator
    Game_Armour& operator=(const Game_Armour& a);

    //Destructor
	~Game_Armour() {};

    //Getters
    inline const ArmourType GetGameArmourTypeEnum() const { return armour_type_enum; }
    inline const ArmourCondition GetGameArmourConditionEnum() const { return armour_condition_enum; }
    inline const default_armour_stats& GetGameArmourStats() const { return stats;  }

    inline const std::string GetGameArmourTypeStr(ArmourType Type) const;
    inline const std::string GetGameArmourConditionStr(ArmourCondition Type) const;
    std::string GetGameItemTypeTypeStr()const {return GetGameArmourTypeStr(armour_type_enum); }
    //Output to ImGui
    void drawIntoImgui() const;
};
#endif
