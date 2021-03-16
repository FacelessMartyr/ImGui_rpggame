#include "Weapon.h"


//Game_Weapon

Game_Weapon::Game_Weapon(const Game_Weapon& a) :Game_Item(a)
{
	this->specs.physical_attack_dmg = a.specs.physical_attack_dmg;
	this->specs.magical_attack_dmg = a.specs.magical_attack_dmg;
	this->specs.weapon_type = a.specs.weapon_type;

    this->weapon_condition_enum = a.weapon_condition_enum;
    this->weapon_type_enum = a.weapon_type_enum;
}

void Game_Weapon::ShowInfo()
{
	std::cout << "specs.bphys_attack_dmg "<<specs.physical_attack_dmg << std::endl;
	std::cout << "specs.magical_attack_dmg "<<specs.magical_attack_dmg << std::endl;
	std::cout << "specs.weapon_type "<<specs.weapon_type << "\n\n";
}

const std::string Game_Weapon::GetGameWeaponConditionStr(WeaponCondition Type) const
{
    switch (Type)
    {
    case Rusty:
        return "Rusty";
    case Shabby:
        return "Shabby";
    case Worn:
        return "Worn";
    case Dull:
        return "Dull";
    case Masterfull:
        return "Masterfull";
    case Heroic:
        return "Heroic";
    case Imperial:
        return "Imperial";
    }
}

const std::string Game_Weapon::GetGameWeaponTypeStr(WeaponType Type) const
{
    switch (Type)
    {
    case sword:
        return "Sword";
    case katana:
        return "Katana";
    }
}

void Game_Weapon::drawIntoImgui() const
{
    //Item name - example : "Rusty Iron Sword" (Condition + ItemName)
    ImGui::TextColored(ItemRarityColor[GetGameItemCondition()-1],"%s ", GetGameWeaponConditionStr(GetGameWeaponConditionEnum()).c_str());
    ImGui::SameLine();
    ImGui::TextColored(ItemRarityColor[GetGameItemRarity()-1], "%s", GetGameItemName().c_str()),
    ImGui::Separator();

    //Item type - example : "Sword" (item_type)
    ImGui::TextColored(ItemStatsColor, "%s", GetGameWeaponTypeStr(GetGameWeaponTypeEnum()).c_str());

    //Item rarity
    ImGui::TextColored(ItemStatsColor, "%s ", "Rarity:");
    ImGui::SameLine();
    ImGui::TextColored(ItemRarityColor[GetGameItemRarity()-1], " %s", GetGameItemRarityStr(GetGameItemRarityEnum()).c_str());

    //Item condition
    ImGui::TextColored(ItemStatsColor, "%s ", "Condition:");
    ImGui::SameLine();
    ImGui::TextColored(ItemRarityColor[GetGameItemCondition() - 1], " %s", GetGameWeaponConditionStr(GetGameWeaponConditionEnum()).c_str());

    //Item stats
    if (GetGameWeaponStats().magical_attack_dmg == 0)
    {
        ImGui::TextColored(ItemStatsColor, "%s ", "Physical damage:");
        ImGui::SameLine();
        ImGui::Text(" %d", GetGameWeaponStats().physical_attack_dmg);
    }
    else
    {
        ImGui::TextColored(ItemStatsColor, "%s ", "Physical damage:");
        ImGui::SameLine();
        ImGui::Text(" %d", GetGameWeaponStats().physical_attack_dmg);

        ImGui::TextColored(ItemStatsColor, "%s ", "Magical damage:");
        ImGui::SameLine();
        ImGui::Text(" %d", GetGameWeaponStats().magical_attack_dmg);
    }

    ImGui::Separator();

    ImGui::TextColored(ItemStatsColor, "%s ", "Requires ");
    ImGui::SameLine();
    ImGui::Text("%d ", GetGameItemStats().item_lvl);
    ImGui::SameLine();
    ImGui::TextColored(ItemStatsColor, "%s", "level");

   /* else
    {

        ImGui::TextColored(ItemLevelReq, "%s ", "Requires ");
        ImGui::SameLine();
        ImGui::Text("%d ", GetGameItemStats().item_lvl);
        ImGui::SameLine();
        ImGui::TextColored(ItemLevelReq, "%s", "level");
    }*/

    ImGui::Separator();
    ImGui::Text("%d ", GetGameItemStats().cost);
    ImGui::SameLine();
    ImGui::TextColored(ItemStatsColor, "%s", "yen");

    
}
