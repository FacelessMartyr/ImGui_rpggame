#ifndef RPGGAME_WINDOWS_H
#define RPGGAME_WINDOWS_H
#include "Character.h"
#include "r_libs.h"
#include "ad_data.h"

#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#include <d3d11.h>

namespace rpggame_wind
{
void CharProfile(const ImGuiWindowFlags& window_flags, bool* CharacterInventory, RECT& windowsize);

}
#endif
