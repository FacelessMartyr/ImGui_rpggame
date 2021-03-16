#pragma once
#ifndef INVENTORY_H
#define INVENTORY_H
#include "Item.h"


class Game_Inventory
{
private:
	enum Size{base_player_inventory=12};
    inline static int current_inv_size = Size::base_player_inventory; 
	//Game_Item* Inventory = new Game_Item[Size::base_player_inventory];
    //std::vector < std::tuple<Game_Item, bool> >Player_Inventory[Size::base_player_inventory];
    //std::pair<std::unique_ptr<Game_Item>, bool>Inventory[base_player_inventory];
    std::vector<std::unique_ptr<Game_Item>>Inventory;
    
	const int ownerid;
    friend class Character;
public:

	Game_Inventory(const int n_ownerid = 121) :ownerid(n_ownerid)
	{
	}
	bool addtoInventory(const int n_item_id);
    bool RemoveFromInventory(const int invslot_id);
	~Game_Inventory() {};//need to save everything
    void InvSlots()
    { 
    }
    inline int GetInvSize() const { return Inventory.size(); }


    const struct std::unique_ptr<Game_Item>& rInventory(const int s_i)const { return Inventory[s_i]; }
    
    
};
#endif
