#include "Armour.h"

Game_Armour::Game_Armour(int n_item_id, int n_cost, int n_rarity, int n_item_type, int n_item_lvl, std::string n_item_name,int n_armour_type, int n_armour, int n_evasion,int n_item_condition):Game_Item(n_item_id, n_cost, n_rarity, n_item_type, n_item_lvl, n_item_name,n_item_condition)
{
	stats.armour_type = n_armour_type;
	stats.armour = n_armour;
	stats.evasion = n_evasion;
}

Game_Armour::Game_Armour(const Game_Armour& a):Game_Item(a)
{
	this->stats.armour_type = a.stats.armour_type;
	this->stats.armour = a.stats.armour;
	this->stats.evasion = a.stats.evasion;
}

Game_Armour& Game_Armour::operator=(const Game_Armour& a)
{
	this->stats.armour_type = a.stats.armour_type;
	this->stats.armour = a.stats.armour;
	this->stats.evasion = a.stats.evasion;
	return *this;
}
