#include "Game_windows.h"


void rpggame_wind::CharProfile(const ImGuiWindowFlags& window_flags, bool *CharacterInventory, RECT& windowsize)
{
    static float col[4];
    static int CrPrBSize_x = double(windowsize.right) / 2.7;
    static int CrPrBSize_y = double(windowsize.bottom) / 1.35;
    CrPrBSize_x = double(windowsize.right) / 2.7;
    CrPrBSize_y = double(windowsize.bottom) / 1.35;

    static int CrPrBPos_x = double(windowsize.right) / 4;
    static int CrPrBPos_y = double(windowsize.bottom) / 5;
    CrPrBPos_x = double(windowsize.right) / 4;
    CrPrBPos_y = double(windowsize.bottom) / 5;

    static float addStatButt = double(CrPrBSize_x) / 11.85;
    addStatButt = double(CrPrBSize_x) / 11.85;

    static float cp_fontscacle = float(windowsize.bottom) / 740.0;
    cp_fontscacle = float(windowsize.bottom) / 740.0;

    float spacing = ImGui::GetStyle().ItemInnerSpacing.x;

    ImGui::SetNextWindowSize(ImVec2(CrPrBSize_x, CrPrBSize_y));
    ImGui::SetNextWindowPos(ImVec2(CrPrBPos_x, CrPrBPos_y));
    ImGui::Begin("Profile", 0, window_flags);
    ImGui::SetWindowFontScale(cp_fontscacle);
    ImGui::TextColored(ImVec4(255, 184, 255, 0), "Name   %s", CharacterList::One->get_nickname().c_str());
    ImGui::Text("\tStats");

    ImGui::Text("Agility - %d", (CharacterList::One->Get_stats().agility));
    ImGui::SameLine(0.0f, spacing);
    ImGui::Button("+", ImVec2(addStatButt, addStatButt));

    ImGui::Text("Strength - %d", (CharacterList::One->Get_stats().strength));
    ImGui::SameLine(0.0f, spacing);
    ImGui::Button("+", ImVec2(addStatButt, addStatButt));

    ImGui::Text("Intelligence - %d", (CharacterList::One->Get_stats().intelligence));
    ImGui::SameLine(0.0f, spacing);
    ImGui::Button("+", ImVec2(addStatButt, addStatButt));
    if (ImGui::Button("Inventory", ImVec2(CrPrBSize_x, CrPrBSize_y / 10)))
    {
        //if (CharacterInventory == false)
           // CharacterInventory = true;
        //else if (CharacterInventory == true)
            //CharacterInventory = false;

    };



    ImGui::End();
}
