#include "Npc.h"

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
