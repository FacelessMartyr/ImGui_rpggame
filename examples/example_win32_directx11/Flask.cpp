#include "Flask.h"

Game_Flask::Game_Flask(const Game_Flask& a):Game_Item(a)
{
	this->heal_type = a.heal_type;
	this->healing = a.healing;
	this->charges = a.charges;
}

Game_Flask& Game_Flask::operator=(const Game_Flask& a)
{
	this->heal_type = a.heal_type;
	this->healing = a.healing;
	this->charges = a.charges;
	return *this;
}
