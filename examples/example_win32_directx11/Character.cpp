#include "Character.h"
//gaining xp and also levelingup character
int Character::character_gainxp()
{
	if ((cXP.Exp + cXP.base_reward) < cXP.ExpLVL)
	{
		cXP.Exp += cXP.base_reward;
	}
	else if ((cXP.Exp + cXP.base_reward) >= cXP.ExpLVL)
	{
		cXP.Exp += cXP.base_reward;
		cXP.Lvl++;
		cXP.ExpLVL = ((cXP.ExpLVL / 100) * 125) + cXP.pile;
		cXP.base_reward = ((cXP.ExpLVL - cXP.Exp) / 5);
	}
    return 0;
}
const void Character::output_InvItem_RequiredLvl(const int s_i) const
{
    ImGui::Separator();
    if (ch_inv.rInventory(s_i).get()->GetGameItemStats().item_lvl < get_char_lvl())
    {
        ImGui::TextColored(ItemStatsColor, "%s ", "Requires ");
        ImGui::SameLine();
        ImGui::Text("%d ", (ch_inv.rInventory(s_i).get()->GetGameItemStats().item_lvl));
        ImGui::SameLine();
        ImGui::TextColored(ItemStatsColor, "%s", "level");
    }
    else
    {
        ImGui::TextColored(ItemLevelReq, "%s ", "Requires ");
        ImGui::SameLine();
        ImGui::TextColored(ItemLevelReq, "%d ", (ch_inv.rInventory(s_i).get()->GetGameItemStats().item_lvl));
        ImGui::SameLine();
        ImGui::TextColored(ItemLevelReq, "%s", "level");
    }
    ImGui::Separator();
}

const void Character::outputI_InvItem_Cost(const int s_i) const
{
    ImGui::Text("%d ", ch_inv.rInventory(s_i).get()->GetGameItemStats().cost);
    ImGui::SameLine();
    ImGui::TextColored(ItemStatsColor, "%s", "yen");
}



