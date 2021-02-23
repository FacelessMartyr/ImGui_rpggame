#include "Weapon.h"


//Game_Weapon

Game_Weapon::Game_Weapon(const Game_Weapon& a) :Game_Item(a)
{
	this->specs.bphys_attack_dmg = a.specs.bphys_attack_dmg;
	this->specs.magical_attack_dmg = a.specs.magical_attack_dmg;
	this->specs.weapon_type = a.specs.weapon_type;
}

void Game_Weapon::ShowInfo()
{
	std::cout << "specs.bphys_attack_dmg "<<specs.bphys_attack_dmg << std::endl;
	std::cout << "specs.magical_attack_dmg "<<specs.magical_attack_dmg << std::endl;
	std::cout << "specs.weapon_type "<<specs.weapon_type << "\n\n";
}
