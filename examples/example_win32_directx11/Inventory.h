#pragma once
#ifndef INVENTORY_H
#define INVENTORY_H
#include "Item.h"
#include "Mediator.h"


class Game_Inventory
{
protected:

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
    //Default constructor
	Game_Inventory(const int n_ownerid = 121) :ownerid(n_ownerid){}

    //Setting mediator
    //void Set_InvMediator(Mediator* n_mediator) { mediator_ = n_mediator; };

    //Destructor. Literally saves evrthng
    ~Game_Inventory() {};

    //Adding item into inventory
	bool addtoInventory(const int n_item_id);

    //Removing item from inventory
    bool RemoveFromInventory(const int invslot_id);
	

    inline const int GetInvSize() const { return Inventory.size(); }


    const struct std::unique_ptr<Game_Item>& rInventory(const int s_i)const { return Inventory[s_i]; }
    
    
};
#endif
