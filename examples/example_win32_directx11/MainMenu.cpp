#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#include <d3d11.h>
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <tchar.h>

#include "r_libs.h"
#include "Character.h"
#include "nlohmann/json.hpp"
#include "Weapon.h"

void CreatingCharacter();
bool RunMainMenu(){


    ImGui::SetNextWindowSize(ImVec2(600, 400));
    ImGui::SetNextWindowPos(ImVec2(825, 464));//position
    static bool showWindow = true;
    if (showWindow)
    {
        ImGui::Begin("RPG Game v0.1", &showWindow);

        if (ImGui::Button("PLAY", ImVec2(585, 120))) {

            showWindow = false;
        }


        if (ImGui::Button("EXIT", ImVec2(585, 120))) { showWindow = false; EXIT_FAILURE; }

        ImGui::Text("is_on = %d", showWindow);
        ImGui::SetWindowFontScale(3);
        
        ImGui::End();
    }
    return 0;
    
    
}
void CreatingCharacter()
{
    static bool showWindow = true;
    if (showWindow)
    {
        ImGui::SetNextWindowSize(ImVec2(900, 700));
        ImGui::SetNextWindowPos(ImVec2(625, 264));//position;
        ImGui::Begin("Creating Character");

        ImGui::SetWindowFontScale(3);
        ImGui::End();

    }
    
}
