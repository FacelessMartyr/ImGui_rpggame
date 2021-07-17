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

    HealType healtype_enum;
public:
    //Default constructor
    Game_Flask():Game_Item()
    {
        heal_type = -1;
        healing = -1;
        charges = 0;
        healtype_enum = HealType(heal_type);
    }

    //Constructor
	Game_Flask(int n_item_id, int n_cost, int n_rarity, int n_item_type,
		int n_item_lvl, std::string n_item_name,
		int n_item_condition,int n_healing, int n_charges,
		int n_heal_type, std::string n_description):Game_Item(n_item_id, n_cost, n_rarity, n_item_type, n_item_lvl, n_item_name, n_item_condition, n_description)
	{
		heal_type = n_heal_type;
		healing = n_healing;
		charges = n_charges;
        healtype_enum = HealType(n_heal_type);

	}

    //Copying constructor
	Game_Flask(const Game_Flask& a);

    //Assingnment operator
	Game_Flask& operator=(const Game_Flask& a);

    //Destructor
    ~Game_Flask() {};

    std::string GetGameItemTypeTypeStr()const { return "Flask"; };

    //Output in ImGui
    void drawIntoImgui()const;
};

#endif
