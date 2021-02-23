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
    std::vector<std::pair<std::unique_ptr<Game_Item>,bool>>Inventory;
    
	const int ownerid;
    friend class Character;
public:

	Game_Inventory(const int n_ownerid = 121) :ownerid(n_ownerid)
	{
        Inventory.resize(int(Size::base_player_inventory));
       for (int i = 0; i < Size::base_player_inventory; i++)
        {
           Inventory[i].first = std::make_unique<Game_Item>(Game_Item());
            Inventory[i].second = false;
        }
	}
	bool addtoInventory(const int n_item_id);
    bool RemoveFromInventory(const int invslot_id);
	~Game_Inventory() {};//need to save everything
    void InvSlots()
    { 
        for (int i = 0; i < Size::base_player_inventory; i++)
        {
            //Inventory[i].first.show_ItemInfo();
            std::cout << Inventory[i].second << ' ';
        }
        std::cout << '\n';

    }
    inline int GetInvSize() const { return Inventory.size(); }


    const struct std::pair<std::unique_ptr<Game_Item>,bool>& rInventory(const int s_i)const { return Inventory[s_i]; }
    
};
#endif
