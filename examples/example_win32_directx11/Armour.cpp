#include "Armour.h"

Game_Armour::Game_Armour(int n_item_id, int n_cost, int n_rarity, int n_item_type, int n_item_lvl, std::string n_item_name,int n_armour_type, int n_armour, int n_evasion,int n_item_condition, std::string n_description):Game_Item(n_item_id, n_cost, n_rarity, n_item_type, n_item_lvl, n_item_name,n_item_condition,n_description)
{
	stats.armour_type = n_armour_type;
	stats.armour = n_armour;
	stats.evasion = n_evasion;

    armour_type_enum = ArmourType(n_armour_type);
    armour_condition_enum = ArmourCondition(n_item_condition);
}

Game_Armour::Game_Armour(const Game_Armour& a):Game_Item(a)
{
	this->stats.armour_type = a.stats.armour_type;
	this->stats.armour = a.stats.armour;
	this->stats.evasion = a.stats.evasion;

    this->armour_type_enum = a.armour_type_enum;
    this->armour_condition_enum = a.armour_condition_enum;
}

Game_Armour& Game_Armour::operator=(const Game_Armour& a)
{
	this->stats.armour_type = a.stats.armour_type;
	this->stats.armour = a.stats.armour;
	this->stats.evasion = a.stats.evasion;

    this->armour_type_enum = a.armour_type_enum;
    this->armour_condition_enum = a.armour_condition_enum;

	return *this;
}

inline const std::string Game_Armour::GetGameArmourTypeStr(ArmourType Type) const
{
    switch (Type)
    {
    case helmet:
        return "Helmet";
    case chest:
        return "Chest";
    case leggins:
        return "Leggins";
    case boots:
        return "Boots";
    }
}

inline const std::string Game_Armour::GetGameArmourConditionStr(ArmourCondition Type) const
{
    switch (Type)
    {

    case Shabby:
        return "Shabby";
    case Worn:
        return "Worn";
    case Sturdy:
        return "Sturdy";
    case Masterfull:
        return "Masterfull";
    case Superb:
        return "Superb";
    case Heroic:
        return "Heroic";
    case Imperial:
        return "Imperial";
    }
}

void Game_Armour::drawIntoImgui() const
{
    //Item name - example : "Rusty Iron Sword" (Condition + ItemName)
    ImGui::TextColored(ItemRarityColor[GetGameItemCondition()-1],"%s ", GetGameArmourConditionStr (GetGameArmourConditionEnum()));
    ImGui::SameLine();
    ImGui::TextColored(ItemRarityColor[GetGameItemRarity()-1], "%s", GetGameItemName()),
    ImGui::Separator();

    //Item type - example : "Chest" (item_type)
    ImGui::TextColored(ItemStatsColor, "%s", GetGameArmourTypeStr(GetGameArmourTypeEnum()));

    //Item rarity
    ImGui::TextColored(ItemStatsColor, "%s ", "Rarity:");
    ImGui::SameLine();
    ImGui::TextColored(ItemRarityColor[GetGameItemRarity()-1], " %s", GetGameItemRarityStr(GetGameItemRarityEnum()));

    //Item condition
    ImGui::TextColored(ItemStatsColor, "%s ", "Condition:");
    ImGui::SameLine();
    ImGui::TextColored(ItemRarityColor[GetGameItemCondition() - 1], " %s", GetGameArmourConditionStr(GetGameArmourConditionEnum()));

    //Item stats
    if (GetGameArmourStats().evasion == 0)
    {
        ImGui::TextColored(ItemStatsColor, "%s ", "Armour:");
        ImGui::SameLine();
        ImGui::Text(" %d", GetGameArmourStats().armour);
    }
    else
    {
        ImGui::TextColored(ItemStatsColor, "%s ", "Armour:");
        ImGui::SameLine();
        ImGui::Text(" %d", GetGameArmourStats().armour);

        ImGui::TextColored(ItemStatsColor, "%s ", "Evasion:");
        ImGui::SameLine();
        ImGui::Text(" %d", GetGameArmourStats().evasion);
    }
}
