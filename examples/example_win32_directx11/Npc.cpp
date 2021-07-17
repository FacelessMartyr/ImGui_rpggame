#include "Npc.h"

GameNPC::GameNPC(const GameNPC& a)
{
    npc_type = a.npc_type;
    npc_type_enum = a.npc_type_enum;

    npc_life = a.npc_life;
    npc_life_enum = a.npc_life_enum;

    npc_status = a.npc_status;
    npc_status_enum = a.npc_status_enum;

    npc_name = a.npc_name;
    npc_level = a.npc_level;
    npc_wealth = a.npc_wealth;
    npc_inv.set_InvSize(a.npc_inv.GetInvSize());
    npc_id = a.npc_id;
}

const GameNPC& GameNPC::operator=(const GameNPC& a)
{
    npc_type = a.npc_type;
    npc_type_enum = a.npc_type_enum;

    npc_life = a.npc_life;
    npc_life_enum = a.npc_life_enum;

    npc_status = a.npc_status;
    npc_status_enum = a.npc_status_enum;

    npc_name = a.npc_name;
    npc_level = a.npc_level;
    npc_wealth = a.npc_wealth;
    npc_inv.set_InvSize(a.npc_inv.GetInvSize());
    npc_id = a.npc_id;
    return *this;
}

inline const std::string GameNPC::GetGameNPCnpc_typeStr(NPC_Type Type) const
{
    switch (Type)
    {
    case Farmer:
        return "Farmer";
    case Merchant:
        return "Merchant";
    case Guardian:
        return "Guardian";
    case Alchemist:
        return "Alchemist";
    case Charmer:
        return "Charmer";
    default:
        return "ErrorName";
    }
}

inline const std::string GameNPC::GetGameNPCnpc_lifeStr(NPC_Life Type) const
{
    switch (Type)
    {
    case Mortal:
        return "Mortal";
    case Immortal:
        return "Immortal";
    default:
        return "Error";
    }
}

inline const std::string GameNPC::GetGameNPCnpc_statusStr(NPC_Status Type) const
{
    switch (Type)
    {
    case Poor:
        return "Poor";
    case Commoner:
        return "Commoner";
    case Affluence:
        return "Affluence";
    case Diligent:
        return "Diligent";
    case Noble:
        return "Noble";
    case Imperial:
        return "Imperial";
    default:
        return "Error";
    }
}

const GameNPC_Merchant& GameNPC_Merchant::operator=(const GameNPC_Merchant& a)
{
    npc_merchant_type = a.npc_merchant_type;
    npc_merchant_type_enum = a.npc_merchant_type_enum;
    return *this;
}
inline const std::string GameNPC_Merchant::GetGameNPC_Merchant_typeStr(NPC_Merchant_Type Type) const
{
    switch (Type)
    {
    case Miner:
        return "Miner";
    case Weaponary:
        return "Weaponary";
    case Jeweller:
        return "Jeweller";
    case Armourer:
        return "Armourer";
    case Goodseller:
        return "Goodseller";
    default:
        return "Error";
    }
}
GameNPC_Guardian::GameNPC_Guardian(const GameNPC_Guardian& a) :GameNPC(a)
{
    npc_guardian_type = a.npc_guardian_type;
    npc_guardian_type_enum = a.npc_guardian_type_enum;
}

inline const std::string GameNPC_Guardian::GetGameNPC_Guardian_typeStr(NPC_Guardian_Type Type) const
{
    switch (Type)
    {
    case Spearman:
        return "Spearman";
    case Swordsman:
        return "Swordsman";
    case Samurai:
        return "Samurai";
    default:
        return "Error";
    }
}

GameNPC_Alchemist::GameNPC_Alchemist(const GameNPC_Alchemist& a) :GameNPC(a)
{
    npc_alchemist_type = a.npc_alchemist_type;
    npc_alchemist_type_enum = a.npc_alchemist_type_enum;
}

GameNPC_Charmer::GameNPC_Charmer(const GameNPC_Charmer& a) :GameNPC(a)
{
    npc_charmer_type = a.npc_charmer_type;
    npc_charmer_type_enum = a.npc_charmer_type_enum;
}

GameNPC_WeaponSmith::GameNPC_WeaponSmith(const GameNPC_WeaponSmith& a) :GameNPC(a)
{
    weaponsmith_type = a.weaponsmith_type;
    weaponsmith_type_enum = a.weaponsmith_type_enum;

    weaponsmith_mastery_type = a.weaponsmith_mastery_type;
    weaponsmith_mastery_type_enum = a.weaponsmith_mastery_type_enum;
}
