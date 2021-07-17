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
    enum NPC_Status{Poor = 0, Commoner = 1, Affluence = 2, Diligent = 3, Noble = 4, Imperial = 5};
    int npc_status;
    NPC_Status npc_status_enum;

    int npc_id;
    std::string npc_name;
    int npc_level;
    int npc_wealth;
    
    Game_Inventory npc_inv;
public:
    //Default constructor
    GameNPC()
    {
        npc_id = 0;
        npc_type = 0;
        npc_type_enum = NPC_Type(npc_type);

        npc_life = 2;
        npc_life_enum = NPC_Life(npc_life);

        npc_status = 0;
        npc_status_enum = NPC_Status(npc_status);

        npc_name = "Unknown";
        npc_level = 1;
        npc_wealth = 0;
        npc_inv.set_InvSize(1);
    }

    //Constructor
    GameNPC(const int n_npc_id, const int n_npc_type, const int n_npc_life, const int n_npc_status, const std::string n_npc_name, const int n_npc_level, const int n_npc_wealth)
    {
        npc_type = n_npc_type;
        npc_type_enum = NPC_Type(npc_type);

        npc_life = n_npc_life;
        npc_life_enum = NPC_Life(npc_life);

        npc_status = n_npc_status;
        npc_status_enum = NPC_Status(npc_status);

        npc_name = n_npc_name;
        npc_level = n_npc_level;
        npc_wealth = n_npc_wealth;
        npc_inv.set_InvSize(20);
        npc_id = n_npc_id;
    };

    //Copying constructor
    GameNPC(const GameNPC& a);

    //Assignment operator
    const GameNPC& operator=(const GameNPC& a);
    //Destructor
    virtual ~GameNPC() {};

    //Getters
    inline const int GetGameNPCnpc_type() const { return npc_type; };
    inline const NPC_Type GetGameNPCnpc_type_enum() const { return npc_type_enum; };
    inline const std::string GetGameNPCnpc_typeStr(NPC_Type Type)const;

    inline const int GetGameNPCnpc_life() const { return npc_life; };
    inline const NPC_Life GetGameNPCnpc_life_enum() const { return npc_life_enum; };
    inline const std::string GetGameNPCnpc_lifeStr(NPC_Life Type) const;

    inline const int GetGameNPCnpc_status() const { return npc_status; };
    inline const NPC_Status GetGameNPCnpc_status_enum() const { return npc_status_enum; };
    inline const std::string GetGameNPCnpc_statusStr(NPC_Status Type) const;

    inline const std::string GetGameNPCname() const { return npc_name; };
    inline const int GetGameNPClevel() const { return npc_level; };
    inline const int GetGameNPCwealth() const { return npc_wealth; };

    //Output into ImGui
    virtual void drawIntoImgui()const = 0;
};

//Merchant
//Derived class
class GameNPC_Merchant : public GameNPC
{
private:
    enum NPC_Merchant_Type {Miner = 0,Weaponary = 1,Jeweller = 2, Armourer = 3,Goodseller = 4};
    int npc_merchant_type;
    NPC_Merchant_Type npc_merchant_type_enum;
public:
    //Default constructor
    GameNPC_Merchant()
    {
        npc_merchant_type = 0;
        npc_merchant_type_enum = NPC_Merchant_Type(0);
    }

    //Constructor
    GameNPC_Merchant(const int n_npc_merchant_type,const int n_npc_id, const int n_npc_type, const int n_npc_life, const int n_npc_status, const std::string n_npc_name, const int n_npc_level, const int n_npc_wealth):GameNPC(n_npc_id,n_npc_type, n_npc_life, n_npc_status, n_npc_name, n_npc_level, n_npc_wealth)
    {
        npc_merchant_type = n_npc_merchant_type;
        npc_merchant_type_enum = NPC_Merchant_Type(npc_merchant_type);
    }
    //Copying constructor
    GameNPC_Merchant(const GameNPC_Merchant& a) :GameNPC(a)
    {
        npc_merchant_type = a.npc_merchant_type;
        npc_merchant_type_enum = a.npc_merchant_type_enum;
    }

    //Assignment operator
    const GameNPC_Merchant& operator=(const GameNPC_Merchant& a);


    //Getters
    inline const int GetGameNPC_Merchant_type() const { return npc_merchant_type; };
    inline const NPC_Merchant_Type GetGameNPC_Merchant_type_enum () const { return npc_merchant_type_enum; };
    inline const std::string GetGameNPC_Merchant_typeStr(NPC_Merchant_Type Type) const;

    //Output into ImGui
    void drawIntoImgui()const
    {
       std::cout << "Itworks";
    }
};

//Guardian
//Derived class
class GameNPC_Guardian : public GameNPC
{
private:
    enum NPC_Guardian_Type {Spearman = 0, Swordsman = 1, Samurai = 2};
    int npc_guardian_type;
    NPC_Guardian_Type npc_guardian_type_enum;
public:
    //Default constructor
    GameNPC_Guardian()
    {
        npc_guardian_type = 1;
        npc_guardian_type_enum = NPC_Guardian_Type(1);
    }

    //Constructor
    GameNPC_Guardian(const int n_npc_guardian_type, const int n_npc_id, const int n_npc_type, const int n_npc_life, const int n_npc_status, const std::string n_npc_name, const int n_npc_level, const int n_npc_wealth) :GameNPC(n_npc_id,n_npc_type, n_npc_life, n_npc_status, n_npc_name, n_npc_level, n_npc_wealth)
    {
        npc_guardian_type = n_npc_guardian_type;
        npc_guardian_type_enum = NPC_Guardian_Type(npc_guardian_type);
    }

    //Copying constructor
    GameNPC_Guardian(const GameNPC_Guardian& a);
    //Getters
    inline const int GetGameNPC_Guardian_type() const { return npc_guardian_type; };
    inline const NPC_Guardian_Type GetGameNPC_Merchant_type_enum() const { return npc_guardian_type_enum; };
    inline const std::string GetGameNPC_Guardian_typeStr(NPC_Guardian_Type Type) const;

    //Output into ImGui
    void drawIntoImgui()const
    {
        std::cout << "Itworks";
    }
};

//Alchemist
//Derived class
class GameNPC_Alchemist : public GameNPC
{
private:
    enum NPC_Alchemist_Type { Potionist = 1 };
    int npc_alchemist_type;
    NPC_Alchemist_Type npc_alchemist_type_enum;
public:
    //Default constructor
    GameNPC_Alchemist()
    {
        npc_alchemist_type = 1;
        npc_alchemist_type_enum = NPC_Alchemist_Type(npc_alchemist_type);
    }

    //Constructor
    GameNPC_Alchemist(const int n_npc_alchemist_type,const int n_npc_id, const int n_npc_type, const int n_npc_life, const int n_npc_status, const std::string n_npc_name, const int n_npc_level, const int n_npc_wealth) :GameNPC(n_npc_id, n_npc_type, n_npc_life, n_npc_status, n_npc_name, n_npc_level, n_npc_wealth)
    {
        npc_alchemist_type = n_npc_alchemist_type;
        npc_alchemist_type_enum = NPC_Alchemist_Type(npc_alchemist_type);
    }
    //Copying constructor
    GameNPC_Alchemist(const GameNPC_Alchemist& a);
    //Output into ImGui
    void drawIntoImgui()const
    {
        std::cout << "Itworks";
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
    //Default constructor
    GameNPC_Charmer()
    {
        npc_charmer_type = 1;
        npc_charmer_type_enum = NPC_Charmer_Type(1);
    }

    //Constructor
    GameNPC_Charmer(const int n_npc_charmer_type, const int n_npc_id, const int n_npc_type, const int n_npc_life, const int n_npc_status, const std::string n_npc_name, const int n_npc_level, const int n_npc_wealth) :GameNPC(n_npc_id,n_npc_type, n_npc_life, n_npc_status, n_npc_name, n_npc_level, n_npc_wealth)
    {
        npc_charmer_type = n_npc_charmer_type;
        npc_charmer_type_enum = NPC_Charmer_Type(npc_charmer_type);
    }
    //Copying constructor
    GameNPC_Charmer(const GameNPC_Charmer& a);
    //Output into ImGui
    void drawIntoImgui()const
    {
        std::cout << "Itworks";
    }
};
//Smith
//Derived class
class GameNPC_WeaponSmith : public GameNPC
{
private:
    enum WeaponSmith_Type { KatanaSmith = 1, SwordSmith = 2 };
    int weaponsmith_type;
    WeaponSmith_Type weaponsmith_type_enum;

    enum WeaponSmith_Mastery { Beginner = 0, Scholar = 1, Assistan = 2, Qualified_Assistant = 3, Expert = 4, Master = 5, Grand_Master = 6 };
    int weaponsmith_mastery_type;
    WeaponSmith_Mastery weaponsmith_mastery_type_enum;

public:
    //Default constructor
    GameNPC_WeaponSmith()
    {
        weaponsmith_type = 0;
        weaponsmith_type_enum = WeaponSmith_Type(0);

        weaponsmith_mastery_type = 0;
        weaponsmith_mastery_type_enum = WeaponSmith_Mastery(0);
    }

    //Constructor
    GameNPC_WeaponSmith(const int n_weaponsmith_type, const int n_weaponsmith_mastery_type,const int n_npc_id, const int n_npc_type, const int n_npc_life, const int n_npc_status, const std::string n_npc_name, const int n_npc_level, const int n_npc_wealth) :GameNPC(n_npc_id, n_npc_type, n_npc_life, n_npc_status, n_npc_name, n_npc_level, n_npc_wealth)
    {
        weaponsmith_type = n_weaponsmith_type;
        weaponsmith_type_enum = WeaponSmith_Type(weaponsmith_mastery_type);

        weaponsmith_mastery_type = n_weaponsmith_mastery_type;
        weaponsmith_mastery_type_enum = WeaponSmith_Mastery(weaponsmith_mastery_type);
    }
    //Copying constructor
    GameNPC_WeaponSmith(const GameNPC_WeaponSmith& a);
    //Output into ImGui
    void drawIntoImgui()const
    {
        std::cout << "Itworks";
    }
};


#endif
