#include "Food.h"

Game_Food::Game_Food(const Game_Food& a):Game_Item(a)
{
	base_heal = a.base_heal;
	nutritious = a.nutritious;
    food_condition_enum = a.food_condition_enum;
}

Game_Food& Game_Food::operator=(const Game_Food& a)
{
    base_heal = a.base_heal;
    nutritious = a.nutritious;
    food_condition_enum = a.food_condition_enum;
    return *this;
}

inline const std::string Game_Food::GetGameFoodConditionStr(FoodCondition Type) const
{
    switch (Type)
    {
    case Ordinary:
        return "Ordinary";
    case Wellmade:
        return "Wellmade";
    }
}

void Game_Food::drawIntoImgui() const
{
    //Item name - example : "Apple Pie" (Condition + ItemName)
    ImGui::TextColored(ItemRarityColor[GetGameItemRarity()-1], "%s ", GetGameFoodConditionStr(GetGameFoodConditionEnum()).c_str());
    ImGui::SameLine();
    ImGui::TextColored(ItemRarityColor[GetGameItemRarity()-1], "%s", GetGameItemName().c_str());
    ImGui::Separator();

    //Item type - example : "Food" (item_type)
    ImGui::TextColored(ItemStatsColor, "%s", "Food");


    //Item rarity
    ImGui::TextColored(ItemStatsColor, "%s ", "Rarity:");
    ImGui::SameLine();
    ImGui::TextColored(ItemRarityColor[GetGameItemRarity()-1], " %s", GetGameItemRarityStr(GetGameItemRarityEnum()).c_str());

    //Item condition
    ImGui::TextColored(ItemStatsColor, "%s ", "Condition:");
    ImGui::SameLine();
    ImGui::TextColored(ItemStatsColor, " %s", GetGameFoodConditionStr(GetGameFoodConditionEnum()).c_str());

    //Item stats
    ImGui::TextColored(ItemStatsColor, "%s ", "Nutritious:");
    ImGui::SameLine();
    ImGui::Text(" %d", GetGameFoodNutritious());

    ImGui::TextColored(ItemStatsColor, "%s ", "Base heal:");
    ImGui::SameLine();
    ImGui::Text(" %d", GetGameFoodBase_Heal());

    ImGui::Separator();
    ImGui::TextColored(ItemStatsColor, "%s ", "Requires ");
    ImGui::SameLine();
    ImGui::Text("%d ", GetGameItemStats().item_lvl);
    ImGui::SameLine();
    ImGui::TextColored(ItemStatsColor, "%s", "level");

    ImGui::Separator();
    ImGui::Text("%d ", GetGameItemStats().cost);
    ImGui::TextColored(ItemStatsColor, "%s", "yen");
}


