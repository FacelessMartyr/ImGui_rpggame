#pragma once
#ifndef ITEM_H
#define ITEM_H
#include "r_libs.h"
#include "imgui.h"

static const std::vector<ImColor> ItemRarityColor
{
    ImColor(140,140,140,255),
    ImColor(66,132,153,255),
    ImColor(22,62,166,255),
    ImColor(55,22,187,255),
    ImColor(204,8,162,255),
    ImColor(255,68,0,255),
    ImColor(123,230,14,255)
};
static const ImColor ItemStatsColor(200,200,200,255);
static const ImColor ItemDescColor(50, 50, 50, 255);
static const ImColor ItemLevelReq(105,0,0,255);

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
    ItemRarity item_rarity_enum;
    ItemType item_type_enum;

	default_stats stats;
	std::string item_name;
	int item_id;
	int item_condition;
	std::string description;

    std::string item_unique_id;

    
	
public:

    //Constructor
	Game_Item(int n_item_id, int n_cost, int n_rarity, int n_item_type, int n_item_lvl, std::string n_item_name, int n_item_condition, std::string n_description);
    //Default constructor
    Game_Item();
    //Destructor
	virtual ~Game_Item() {};
    //Copying constructor
	Game_Item(const Game_Item &a);
    //Assignment operator
	Game_Item& operator=(const Game_Item& a);

    //debug func
    virtual void show_ItemInfo();

    //Getters
    const default_stats& GetGameItemStats() const { return stats; };
    const int GetGameItemID()const { return item_id; };
    const std::string& GetGameItemName() const { return item_name; };
    const int GetGameItemCondition() const { return item_condition; };
    const std::string GetGameItemRarityStr(ItemRarity Type) const;
    const int GetGameItemRarity() const { return stats.rarity; };
    const ItemRarity GetGameItemRarityEnum() const { return item_rarity_enum; };
    const std::string GetGameItemTypeStr(ItemType Type) const;
    const ItemType GetGameItemTypeEnum() const { return item_type_enum; };

    const std::string GetGameItemDesc() const { return description; };
    const std::string GetGameItemUniqueID() const { return item_unique_id; }
    //Setters
    void SetItemUniqueID(std::string n_item_unique_id) { item_unique_id = n_item_unique_id; };
    
    //Output to ImGui
    virtual void drawIntoImgui()const = 0;
    virtual std::string GetGameItemTypeTypeStr()const = 0;


   
};
#endif
