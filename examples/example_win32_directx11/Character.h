#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include "Inventory.h"
class Character
{
private:
	struct CharStats
	{
		int strength;
		int agility;
		int intelligence;

	};
	struct CharXP
	{
		enum Leveling { min = 1, max = 100 };
		enum pXp { pile = 600 };
		int Lvl = 1;
		long Exp = 0;
		long ExpLVL = 400;
		long Exp_to_lvlup = 400;
		int base_reward = 100;
	};

	enum CharacterRole { soon };
    enum CharacterGender{male=0,female=1};

	const int c_id; //inventory id

	CharStats cStats;//player stats agl str int
    CharXP cXP;
	
	Game_Inventory ch_inv; //inventory obj

    std::string nickname;
    bool gender;
    int statpoints_left;

    int wealth;
public:
	Character(std::string n_nickname = "Steve", bool n_gender = 0):c_id(121)
	{

		cXP.Exp_to_lvlup = 400;
		cXP.ExpLVL = 400;
		cXP.Exp = 0;
		cXP.Lvl = 1;
		cXP.base_reward = 100;
		cStats.strength = 4;
		cStats.agility = 4;
		cStats.intelligence = 4;
		statpoints_left = 6;
        wealth = 0;
        nickname = n_nickname;
        gender = n_gender;

	};
	~Character() {};//saves everything


	int character_gainxp();//character add exp


    //Adding character stats
    void character_addstats_agility() {
        if (statpoints_left > 0)
        {
            cStats.agility++;
            statpoints_left--;
        }
    };//Adding character stats agility  

    void character_addstats_strength() {
        if (statpoints_left > 0)
        {
            cStats.strength++;
            statpoints_left--;
        }
    };//Adding character stats strength

    void character_addstats_intelligence() {
        if (statpoints_left > 0)
        {
            cStats.intelligence++;
            statpoints_left--;
        }
    };//Adding character stats intelligence


    //Getters
    std::string get_nickname() {return nickname;}  //returns nickname
             //returns gender
    const CharStats& Get_stats()const { return cStats; }; //returns struct obj stats
    const int InvSize() const{return ch_inv.GetInvSize(); }   //returns current inventory size
    const int get_wealth() const { return wealth; };
    const int get_char_lvl() const { return cXP.Lvl; };
    const int get_char_explvl() const { return cXP.ExpLVL; }
    const int get_char_exp() const { return cXP.Exp; }
    const int get_char_gender() const { return gender; }
    const int get_statpoints_left() const { return statpoints_left; }
    void Char_AddItem(const int it_id) {
        ch_inv.addtoInventory(it_id);
    }
    void Char_ShowSlots()
    {
        ch_inv.InvSlots();
    }
    const struct std::unique_ptr<Game_Item>& rInventory(const int s_i) const { return ch_inv.rInventory(s_i); }
    
    void show_stats()
    {
        std::cout << cStats.strength << " cStats.strength" << std::endl;
        std::cout << cStats.agility << " cStats.agility" << std::endl;
        std::cout << cStats.intelligence << " cStats.intelligence " << "\n\n";
    };//useless func    
};
#endif











