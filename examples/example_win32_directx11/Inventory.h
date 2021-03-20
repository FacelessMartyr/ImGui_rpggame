#pragma once
#ifndef INVENTORY_H
#define INVENTORY_H
#include "Item.h"
#include "Mediator.h"


class Game_Inventory
{
protected:

private:
	enum Size{base_npc_inventory = 20, base_player_inventory=12};
    int current_inv_size; 
	//Game_Item* Inventory = new Game_Item[Size::base_player_inventory];
    //std::vector < std::tuple<Game_Item, bool> >Player_Inventory[Size::base_player_inventory];
    //std::pair<std::unique_ptr<Game_Item>, bool>Inventory[base_player_inventory];
    std::vector<std::unique_ptr<Game_Item>>Inventory;

    
	const int ownerid;
    friend class Character;
public:
    //Default constructor
	Game_Inventory(const int n_inv_size = 12, const int n_ownerid = 121) :ownerid(n_ownerid), current_inv_size(n_inv_size){}

    //void Set_InvMediator(Mediator* n_mediator) { mediator_ = n_mediator; };

    //Destructor. Literally saves evrthng
    ~Game_Inventory() {};

    //Adding item into inventory
	bool addtoInventory(const int n_item_id);

    //Removing item from inventory
    bool RemoveFromInventory(const int invslot_id);

    //Setters
    void set_InvSize(const int n_inv_size) { current_inv_size = n_inv_size; };

    //Getters
    inline const int GetInvSize() const { return Inventory.size(); }
    const struct std::unique_ptr<Game_Item>& rInventory(const int s_i)const { return Inventory[s_i]; }
    
    
};
#endif
