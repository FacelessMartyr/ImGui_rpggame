#include "Flask.h"

Game_Flask::Game_Flask(const Game_Flask& a):Game_Item(a)
{
	this->heal_type = a.heal_type;
	this->healing = a.healing;
	this->charges = a.charges;
    this->healtype_enum = a.healtype_enum;
}

Game_Flask& Game_Flask::operator=(const Game_Flask& a)
{
	this->heal_type = a.heal_type;
	this->healing = a.healing;
	this->charges = a.charges;
    this->healtype_enum = a.healtype_enum;
	return *this;
}

void Game_Flask::drawIntoImgui() const
{
    ;
}
