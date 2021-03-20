#pragma once
#ifndef NPC_H
#define NPC_H
#include "Inventory.h"
//Base class
class GameNPC
{
private:
    //Npc type
    enum NPC_Type{Farmer = 0,Merchant = 1,Guardian = 2, Alchemist = 3,Charmer = 4};
    int npc_type;
    NPC_Type npc_type_enum;

    //Npc vulnerability
    enum NPC_Life{Mortal = 1, Immortal = 2};
    int npc_life;
    NPC_Life npc_life_enum;

    //Npc status
    enum NPC_Status{};
    int npc_status;
    NPC_Status npc_status_enum;

    int npc_wealth;
    Game_Inventory npc_inv;
public:
    //Default constructor
    GameNPC()
    {
        npc_type = 0;
        npc_type_enum = NPC_Type(npc_type);
    }
    //Constructor
    GameNPC()
    {
        npc_inv.set_InvSize(20);
    };
    ~GameNPC() {};
    virtual void foo() = 0;
};

//Merchant
//Derived class
class GameNPC_Merchant : public GameNPC
{
private:
    enum NPC_Merchant_Type {};
    int npc_merchant_type;
    NPC_Merchant_Type npc_merchant_type_enum;
public:
    GameNPC_Merchant():GameNPC()
    {

    }
};

//Guardian
//Derived class
class GameNPC_Guardian : public GameNPC
{
private:
    enum NPC_Guardian_Type {};
    int npc_guardian_type;
    NPC_Guardian_Type npc_guardian_type_enum;
public:
    GameNPC_Guardian() :GameNPC()
    {

    }
};

//Alchemist
//Derived class
class GameNPC_Alchemist : public GameNPC
{
private:
    enum NPC_Alchemist_Type {};
    int npc_alchemist_type;
    NPC_Alchemist_Type npc_alchemist_type_enum;
public:
    GameNPC_Alchemist() :GameNPC()
    {

    }
};

//Charmer
//Derived class
class GameNPC_Charmer : public GameNPC
{
private:
    enum NPC_Charmer_Type {};
    int npc_charmer_type;
    NPC_Charmer_Type npc_charmer_type_enum;
public:
    GameNPC_Charmer():GameNPC()
    {

    }

};
#endif
