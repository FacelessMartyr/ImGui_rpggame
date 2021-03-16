#include "Inventory.h"

#include "ad_data.h"
#include "GameContent.h"
static GameContent c_data;
bool Game_Inventory::addtoInventory(const int n_itemid)
{
    if (n_itemid>0&&n_itemid<300)
    {
        for (int i = 0; i < c_data.contentWeapons_size(); i++)
        {
            if (n_itemid == ad_content::weapons_data[i].GetGameItemID()) {

                Inventory.emplace_back(std::make_unique<Game_Weapon>(ad_content::weapons_data[i]));
            }
        }   
        
    }
    else if (n_itemid > 299 && n_itemid < 600)
    {
        for (int i = 0; i < c_data.contentFood_size(); i++)
        {
            if (n_itemid == ad_content::food_data[i].GetGameItemID()) {

                Inventory.emplace_back(std::make_unique<Game_Food>(ad_content::food_data[i]));
            }
        }
    }
    else if (n_itemid > 599 && n_itemid < 900)
    {
        for (int i = 0; i < c_data.contentArmour_size(); i++)
        {
            if (n_itemid == ad_content::armour_data[i].GetGameItemID()) {

                Inventory.emplace_back(std::make_unique<Game_Armour>(ad_content::armour_data[i]));
                
            }
        }
    }
    else if (n_itemid > 899 && n_itemid < 1200)
    {
        for (int i = 0; i < c_data.contentFlask_size(); i++)
        {
            if (n_itemid == ad_content::flask_data[i].GetGameItemID()) {

                    Inventory.emplace_back(std::make_unique<Game_Flask>(ad_content::flask_data[i]));
            }
        }
    }
    else if (n_itemid > 1199 && n_itemid < 1500)
    {
        for (int i = 0; i < ad_content::loot_data.size(); i++)
        {
            if (n_itemid == ad_content::loot_data[i].GetGameItemID()) {

                Inventory.emplace_back(std::make_unique<Game_Loot>(ad_content::loot_data[i]));
            }
        }
    }
    else
    {
        std::cout << "Wrong id" << std::endl;
        return 1;
    }
}

bool Game_Inventory::RemoveFromInventory(const int invslot_id)
{
   
    return 0;//temporary
}
