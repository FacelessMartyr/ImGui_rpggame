// Dear ImGui: standalone example application for DirectX 11
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#include <d3d11.h>
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <tchar.h>


#include "nlohmann/json.hpp"
#include "r_libs.h"


 
#include "Game_windows.h"

//game func



using nlohmann::json;
using namespace std;

void load_gamecontent();
// Data
static ID3D11Device*            g_pd3dDevice = NULL;
static ID3D11DeviceContext*     g_pd3dDeviceContext = NULL;
static IDXGISwapChain*          g_pSwapChain = NULL;
static ID3D11RenderTargetView*  g_mainRenderTargetView = NULL;

// Forward declarations of helper functions
bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void CreateRenderTarget();
void CleanupRenderTarget();
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Main code
int main(int, char**)
{
    // Create application window
    //ImGui_ImplWin32_EnableDpiAwareness();
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, _T("ImGui Example"), NULL };
    ::RegisterClassEx(&wc);
    HWND hwnd = ::CreateWindow(wc.lpszClassName, _T("RPG Game"), WS_OVERLAPPEDWINDOW, 100, 100, 1920, 1080, NULL, NULL, wc.hInstance, NULL);

    // Initialize Direct3D
    if (!CreateDeviceD3D(hwnd))
    {
        CleanupDeviceD3D();
        ::UnregisterClass(wc.lpszClassName, wc.hInstance);
        return 1;
    }

    // Show the window
    ::ShowWindow(hwnd, SW_SHOWDEFAULT);
    ::UpdateWindow(hwnd);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    
    io.Fonts->AddFontFromFileTTF("fonts/AngelRhapsodyRegular-ZVGJz.ttf", 46);
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

    // Setup Platform/Renderer backends
    ImGui_ImplWin32_Init(hwnd);
    ImGui_ImplDX11_Init(g_pd3dDevice, g_pd3dDeviceContext);

    // Load Fonts
    // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
    // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
    // - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
    // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
    // - Read 'docs/FONTS.md' for more instructions and details.
    // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/ProggyTiny.ttf", 10.0f);
    //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
    //IM_ASSERT(font != NULL);

    // Our state
    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    // Main loop
    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    while (msg.message != WM_QUIT)
    {
        // Poll and handle messages (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        if (::PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            continue;
        }
        
        // Start the Dear ImGui frame
        ImGui_ImplDX11_NewFrame();  
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();



        // Starts..
        {
            static bool no_titlebar = true;
            static bool no_scrollbar = true;
            static bool no_menu = true;
            static bool no_move = false;
            static bool no_resize = true;
            static bool no_collapse = false;
            static bool no_close = true;
            static bool no_nav = false;
            static bool no_background = false;
            static bool no_bring_to_front = false;

            ImGuiWindowFlags window_flags = 0;
            if (no_titlebar)        window_flags |= ImGuiWindowFlags_NoTitleBar;
            if (no_scrollbar)       window_flags |= ImGuiWindowFlags_NoScrollbar;
            if (!no_menu)           window_flags |= ImGuiWindowFlags_MenuBar;
            if (no_move)            window_flags |= ImGuiWindowFlags_NoMove;
            if (no_resize)          window_flags |= ImGuiWindowFlags_NoResize;
            if (no_collapse)        window_flags |= ImGuiWindowFlags_NoCollapse;
            if (no_nav)             window_flags |= ImGuiWindowFlags_NoNav;
            if (no_background)      window_flags |= ImGuiWindowFlags_NoBackground;
            if (no_bring_to_front)  window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus;
            if (no_close);        // Don't pass our bool* to Begin

            static bool showWindow = true;//menu play exit window
            static bool showCharCr = false;//creating character window
            static bool CharProfile = false;//character profile
            static bool CharacterInventory = false;//character inventory

            //static Character *One;//main player
          


                //window scale
                static RECT windowsize;
                GetClientRect(hwnd, &windowsize);
                static int w_height = windowsize.bottom;
                static int w_width = windowsize.right;

            
           
            //menu window 
            static int FirstMenuSize_x = 600;
            static int FirstMenuSize_y = 400;
            static int FirstMenuPos_x = 680;
            static int FirstMenuPos_y = 364;
            
            //scaling position and size of menu window
            {
                FirstMenuSize_x = double(windowsize.right) / 3.2;
                FirstMenuSize_y = double(windowsize.bottom) / 3;
                FirstMenuPos_x = double(windowsize.right) / 2.8;
                FirstMenuPos_y = double(windowsize.bottom) / 2.8;
            }

            

            ImGui::SetNextWindowSize(ImVec2(FirstMenuSize_x, FirstMenuSize_y));
            ImGui::SetNextWindowPos(ImVec2(FirstMenuPos_x, FirstMenuPos_y));//position
            
            //:::: MAIN MENU
            //One = new Character(nicknamo, gender);
            
            /*static Character* One = new Character("Steve", 0);
            load_gamecontent();
            One->Char_AddItem(4);
            One->Char_ShowSlots();*/
           
            if (showWindow)
            {
                static int PlayButtSize_x = double(windowsize.right)/3.2;
                static int PlayButtSize_y = double(windowsize.bottom)/9;
                ImGui::Begin("RPG Game v0.1", &showWindow, window_flags);
                PlayButtSize_x = double(windowsize.right) / 3.2;
                PlayButtSize_y = double(windowsize.bottom) / 9;
                if (ImGui::Button("PLAY", ImVec2(PlayButtSize_x, PlayButtSize_y))) {
                    showWindow = false; showCharCr = true;
                    load_gamecontent();
                }


                if (ImGui::Button("EXIT", ImVec2(PlayButtSize_x, PlayButtSize_y))) { showWindow = false; EXIT_FAILURE; }
                if (ImGui::Button("REFRESH", ImVec2(PlayButtSize_x, PlayButtSize_y)))
                {
                    w_height = windowsize.bottom;
                    w_width = windowsize.right;
                }
                
                ImGui::Text("Height %d", w_height);
                ImGui::Text("Width  %d", w_width);
                static float mm_fontscacle = float(windowsize.bottom) /640.0;
                mm_fontscacle = float(windowsize.bottom) / 640.0;
                ImGui::SetWindowFontScale(mm_fontscacle);

                ImGui::End();
            }
            //:::: MAIN MENU
            //

            
            //character characteristics
            
            
            static char nickname[30];
            static char hint[]{"Nickname"};
            static int gender = 0;
            static int items_count;
            static const char *  genders[]{ "Male","Female" };
            static string s_info = "Good";
            size_t nn_size = 29;

            //:::: CREATING CHARACTER
            //
            if (showCharCr)
            {

                static int CrChBSize_x = double(windowsize.right) / 2.7;
                static int CrChBSize_y = double(windowsize.bottom) / 1.35;
                CrChBSize_x = double(windowsize.right) / 2.7;
                CrChBSize_y = double(windowsize.bottom) / 1.35;

                static int CrChBPos_x = double(windowsize.right) / 3;
                static int CrChBPos_y = double(windowsize.bottom) / 4;
                CrChBPos_x = double(windowsize.right) / 3;
                CrChBPos_y = double(windowsize.bottom) / 4;


                ImGui::SetNextWindowSize(ImVec2(CrChBSize_x, CrChBSize_y));
                ImGui::SetNextWindowPos(ImVec2(CrChBPos_x, CrChBPos_y));//position;


                ImGui::Begin("Creating Character",0,window_flags);
                
                
                ImGui::InputTextWithHint("", hint, nickname,nn_size);
                ImGui::Text("");
                ImGui::ListBox("Gender",&gender,genders,IM_ARRAYSIZE(genders),2);

                static float mm_fontscacle = float(windowsize.bottom) / 780.0;
                mm_fontscacle = float(windowsize.bottom) / 780.0;
                ImGui::SetWindowFontScale(mm_fontscacle);

                ImGui::Text(nickname);
                if(ImGui::Button("Create", ImVec2(CrChBSize_x, CrChBSize_y / 10)))
                {
                    CharacterList::One = new Character(nickname, gender);
                    showCharCr = false;
                    CharProfile = true;
                    //test
                    CharacterList::One->Char_AddItem(4);
                    CharacterList::One->Char_AddItem(3);
                    CharacterList::One->Char_ShowSlots();
                    //test
                }
                
                if (ImGui::Button("Back", ImVec2(CrChBSize_x, CrChBSize_y / 10)))
                {
                    showCharCr = false;
                    showWindow = true;
                };
                
                ImGui::End();
                
            }
                //:::: CREATING CHARACTER
                //

                //:::: CHARACTER PROFILE
                //
            if (CharProfile)
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

                ImGui::SetNextWindowSize(ImVec2(CrPrBSize_x,CrPrBSize_y));
                ImGui::SetNextWindowPos(ImVec2(CrPrBPos_x, CrPrBPos_y));
                ImGui::Begin("Profile", 0, window_flags);
                ImGui::SetWindowFontScale(cp_fontscacle);
                ImGui::TextColored(ImVec4(255,184,255,0),"Name   %s", CharacterList::One->get_nickname().c_str());
                ImGui::Text("\tStats");

                ImGui::Text("Agility - %d",(CharacterList::One->Get_stats().agility));
                ImGui::SameLine(0.0f, spacing);
                ImGui::Button("+",ImVec2(addStatButt, addStatButt));

                ImGui::Text("Strength - %d",(CharacterList::One->Get_stats().strength));
                ImGui::SameLine(0.0f, spacing); 
                ImGui::Button("+",ImVec2(addStatButt, addStatButt));

                ImGui::Text("Intelligence - %d",(CharacterList::One->Get_stats().intelligence));
                ImGui::SameLine(0.0f, spacing);
                ImGui::Button("+",ImVec2(addStatButt, addStatButt));
                if(ImGui::Button("Inventory", ImVec2(CrPrBSize_x, CrPrBSize_y / 10)))
                {
                    if (CharacterInventory == false)
                        CharacterInventory = true;
                    else if (CharacterInventory == true)
                        CharacterInventory = false;

                };
                
                
                
                ImGui::End();


            }
            
            //if (CharProfile)
            //rpggame_wind::CharProfile(window_flags, &CharacterInventory, windowsize);
                //:::: CHARACTER INVENTORY
            if (CharacterInventory)
            {
                static int CrInvBSize_x = double(windowsize.right) / 2.7;
                static int CrInvBSize_y = double(windowsize.bottom) / 1.35;
                CrInvBSize_x = double(windowsize.right) / 2.7;
                CrInvBSize_y = double(windowsize.bottom) / 1.35;

                static float invSlotSize = double(CrInvBSize_x) / 4.2;
                invSlotSize = double(CrInvBSize_x) / 4.2;

                static int CrInvBPos_x = double(windowsize.right) / 1.61;
                static int CrInvBPos_y = double(windowsize.bottom) / 5;
                CrInvBPos_x = double(windowsize.right) / 1.61;
                CrInvBPos_y = double(windowsize.bottom) / 5;

                ImGui::SetNextWindowSize(ImVec2(CrInvBSize_x, CrInvBSize_y));
                ImGui::SetNextWindowPos(ImVec2(CrInvBPos_x, CrInvBPos_y));
                ImGui::Begin("Your inventory", 0, window_flags);
                
                for (int i = 0; i < CharacterList::One->InvSize(); i++)
                {
                    
                    if ((i % 4) != 0)
                    {
                        ImGui::SameLine();
                    }
                    ImGui::Button(CharacterList::One->rInventory(i).first.get()->GetGameItemName().c_str(), ImVec2(invSlotSize, invSlotSize));
                }
                ImGui::End();
            }
                //:::: CHARACTER PROFILE
                //
            if (true)
            {
                

            }
            

        }

        // 3. Show another simple window.

        // Rendering
        ImGui::Render();
        g_pd3dDeviceContext->OMSetRenderTargets(1, &g_mainRenderTargetView, NULL);
        g_pd3dDeviceContext->ClearRenderTargetView(g_mainRenderTargetView, (float*)&clear_color);
        ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

        g_pSwapChain->Present(1, 0); // Present with vsync
        //g_pSwapChain->Present(0, 0); // Present without vsync
    }

    // Cleanup
    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceD3D();
    ::DestroyWindow(hwnd);
    ::UnregisterClass(wc.lpszClassName, wc.hInstance);

    return 0;
}

// Helper functions

bool CreateDeviceD3D(HWND hWnd)
{
    // Setup swap chain
    DXGI_SWAP_CHAIN_DESC sd;
    ZeroMemory(&sd, sizeof(sd));
    sd.BufferCount = 2;
    sd.BufferDesc.Width = 0;
    sd.BufferDesc.Height = 0;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = hWnd;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = TRUE;
    sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

    UINT createDeviceFlags = 0;
    //createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
    D3D_FEATURE_LEVEL featureLevel;
    const D3D_FEATURE_LEVEL featureLevelArray[2] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0, };
    if (D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, &g_pSwapChain, &g_pd3dDevice, &featureLevel, &g_pd3dDeviceContext) != S_OK)
        return false;

    CreateRenderTarget();
    return true;
}

void CleanupDeviceD3D()
{
    CleanupRenderTarget();
    if (g_pSwapChain) { g_pSwapChain->Release(); g_pSwapChain = NULL; }
    if (g_pd3dDeviceContext) { g_pd3dDeviceContext->Release(); g_pd3dDeviceContext = NULL; }
    if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = NULL; }
}

void CreateRenderTarget()
{
    ID3D11Texture2D* pBackBuffer;
    g_pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
    g_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &g_mainRenderTargetView);
    pBackBuffer->Release();
}

void CleanupRenderTarget()
{
    if (g_mainRenderTargetView) { g_mainRenderTargetView->Release(); g_mainRenderTargetView = NULL; }
}

// Forward declare message handler from imgui_impl_win32.cpp
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Win32 message handler
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
        {
            CleanupRenderTarget();
            g_pSwapChain->ResizeBuffers(0, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam), DXGI_FORMAT_UNKNOWN, 0);
            CreateRenderTarget();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        ::PostQuitMessage(0);
        return 0;
    }
    return ::DefWindowProc(hWnd, msg, wParam, lParam);
}
