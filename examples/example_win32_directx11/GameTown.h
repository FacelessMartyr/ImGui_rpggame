#pragma once
#ifndef GAMETOWN_H
#define GAMETOWN_H
#include "ad_data.h"
class GameTown
{
private:
    enum Town_Rank{};
    
    std::shared_ptr<Character> Player;
    std::vector<std::unique_ptr<GameNPC>> town_npc;
    bool player_presence;
    std::string town_name;
    //Available quests vector<quest> quests
public:
    //Default constructor
    GameTown()
    {
        Player = nullptr;
        player_presence = false;
        town_name = { "Unknown" };
    }

    //Constructor
    GameTown(const std::string n_town_name,)
    {
    
    }

    //Functions
    
    
    //bool getters
    inline const bool Player_Presense() const { return player_presence; };
};
#endif
