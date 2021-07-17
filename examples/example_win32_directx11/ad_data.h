#pragma once
#ifndef AD_DATA_H
#define AD_DATA_H

#include "Weapon.h"
#include "Food.h"
#include "Armour.h"
#include "Flask.h"
#include "Loot.h"
#include <vector>

#include "Npc.h"
#include "Character.h"
namespace CharacterList
{
    static std::shared_ptr<Character> One;
};
namespace InventoryList
{
    //soon
};
namespace ad_content
{
    inline std::vector<Game_Weapon> weapons_data;//id 1 - 299
    inline std::vector<Game_Food> food_data;//300 - 599
    inline std::vector<Game_Armour> armour_data;//600 - 899
    inline std::vector<Game_Flask> flask_data;//900 - 1190
    inline std::vector<Game_Loot> loot_data;//1190 - 1499
    inline std::vector<GameNPC_Alchemist> alchemist_npc_data;
    inline std::vector<GameNPC_Merchant> merchant_npc_data;
    inline std::vector<GameNPC_Guardian> guardian_npc_data;
    inline std::vector<GameNPC_Charmer> charmer_npc_data;
    inline std::vector<GameNPC_WeaponSmith> weaponsmith_npc_data;
}

#endif
