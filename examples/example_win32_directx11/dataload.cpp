
#include "GameContent.h"
#include "Inventory.h"
#include "ad_data.h"
static GameContent c_data;
void load_gamecontent()
{
	//loot=0,weapon=1,armour=2,food=3,flask=4
	//GameContent item_weapons;
    
    c_data.loadData_Food();
    c_data.loadData_Armoury();
    c_data.loadData_Weapons();
    c_data.loadData_Flasks();
    c_data.loadData_Loot();

};
