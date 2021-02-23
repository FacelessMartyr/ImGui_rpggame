#include "Item.h"

Game_Item::Game_Item(const int n_item_id, int n_cost, int n_rarity, int n_item_type, int n_item_lvl, std::string n_item_name, int n_item_condition)
{
	stats.cost = n_cost; stats.rarity = n_rarity;
	stats.item_type = n_item_type; stats.item_lvl = n_item_lvl;
	item_name = n_item_name;
	item_id = n_item_id;
	item_condition = n_item_condition;
}

Game_Item::Game_Item()
{
	item_id = -1;
	stats.cost = -1; stats.rarity = -1;
	stats.item_type = -1; stats.item_lvl = -1;
	item_name = "none";
	item_condition = -1;
}

Game_Item::Game_Item(const Game_Item& a)
{
	this->stats.cost = a.stats.cost;
	this->stats.rarity = a.stats.rarity;
	this->stats.item_type = a.stats.item_type;
	this->stats.item_lvl = a.stats.item_lvl;
	this->item_id = a.item_id;
	this->item_name = a.item_name;
	this->item_condition = a.item_condition;
}

Game_Item & Game_Item::operator=(const Game_Item& a)
{
	this->stats.cost = a.stats.cost;
	this->stats.rarity = a.stats.rarity;
	this->stats.item_type = a.stats.item_type;	
	this->stats.item_lvl = a.stats.item_lvl;
	this->item_id = a.item_id;
	this->item_name = a.item_name;
	this->item_condition = a.item_condition;
	return *this;
}

void Game_Item::show_ItemInfo()
{
	std::cout << "stats.cost " << stats.cost << std::endl;
	std::cout << "stats.rarity " << stats.rarity << std::endl;
	std::cout << "stats.item_type " << stats.item_type << std::endl;
	std::cout << "stats.item_lvl " << stats.item_lvl << std::endl;
	std::cout << "item_name " << item_name << std::endl;
	std::cout << "item_id " << item_id << std::endl;
	
}
