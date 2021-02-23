#include "Food.h"

Game_Food::Game_Food(const Game_Food& a):Game_Item(a)
{
	base_heal = a.base_heal;
	nutritious = a.nutritious;
}
