#include "GameContent.h"
using nlohmann::json;
//loading items/weapons 


void GameContent::loadData_Weapons()
{
    //---filenames container
    std::set<std::filesystem::path> weapon_sorted_by_name;

    //---inserting file names into set
    for (auto& entry : std::filesystem::directory_iterator(items_pathlist[1]))
        weapon_sorted_by_name.insert(entry.path());

    std::ifstream file_input;
    std::string serialised_data;//raw_data
    std::string temp;//temp data from loop
    char* ptr = NULL;
    for (auto& filename : weapon_sorted_by_name)
    {
        file_input.open(filename, std::ifstream::app, std::ifstream::binary);
        
        while (!file_input.eof())
        {
            ptr = new char[36];
            file_input.getline(ptr, 35, '\n');
            serialised_data += ptr;
            delete[]ptr;
        }
        std::cout << serialised_data << "\n\n";
        file_input.close();
        json parsed_file = json::parse(serialised_data);
        serialised_data = "";
        ad_content::weapons_data.push_back(Game_Weapon(parsed_file["item_id"].get<int>(),parsed_file["cost"].get<int>(), parsed_file["rarity"].get<int>(), parsed_file["item_type"].get<int>(), parsed_file["item_lvl"].get<int>(), parsed_file["item_name"].get<std::string>(),
            parsed_file["bphys_attack_dmg"].get<int>(), parsed_file["magical_attack_dmg"].get<int>(), parsed_file["weapon_type"].get<int>(), parsed_file["item_condition"].get<int>()));
        
    }

}
void GameContent::loadData_Food()
{
    
        

        //---filenames container
        std::set<std::filesystem::path> food_sorted_by_name;

        //---inserting file names into set
        for (auto& entry : std::filesystem::directory_iterator(items_pathlist[3]))
            food_sorted_by_name.insert(entry.path());

        std::ifstream file_input;
        std::string serialised_data;//raw_data
        std::string temp;//temp data from loop
        char* ptr = NULL;
        for (auto& filename : food_sorted_by_name)
        {
            file_input.open(filename, std::ifstream::app, std::ifstream::binary);

            while (!file_input.eof())
            {
                ptr = new char[36];
                file_input.getline(ptr, 35, '\n');
                serialised_data += ptr;
                delete[]ptr;
            }
            std::cout << serialised_data << "\n\n";
            file_input.close();
            json parsed_file = json::parse(serialised_data);
            serialised_data = "";
            ad_content::food_data.push_back(Game_Food(parsed_file["item_id"].get<int>(), parsed_file["cost"].get<int>(), parsed_file["rarity"].get<int>(), parsed_file["item_type"].get<int>(), parsed_file["item_lvl"].get<int>(), parsed_file["item_name"].get<std::string>(),
                parsed_file["base_heal"].get<int>(), parsed_file["nutritious"].get<int>(),parsed_file["item_condition"].get<int>()));

        }
    
}
void GameContent::loadData_Flasks()
{
    //---filenames container
    std::set<std::filesystem::path> flasks_sorted_by_name;

    //---inserting file names into set
    for (auto& entry : std::filesystem::directory_iterator(items_pathlist[4]))
        flasks_sorted_by_name.insert(entry.path());

    std::ifstream file_input;
    std::string serialised_data;//raw_data
    std::string temp;//temp data from loop
    char* ptr = NULL;
    for (auto& filename : flasks_sorted_by_name)
    {
        file_input.open(filename, std::ifstream::app, std::ifstream::binary);

        while (!file_input.eof())
        {
            ptr = new char[36];
            file_input.getline(ptr, 35, '\n');
            serialised_data += ptr;
            delete[]ptr;
        }
        std::cout << serialised_data << "\n\n";
        file_input.close();
        json parsed_file = json::parse(serialised_data);
        serialised_data = "";
        ad_content::flask_data.push_back(Game_Flask(parsed_file["item_id"].get<int>(), parsed_file["cost"].get<int>(), parsed_file["rarity"].get<int>(), parsed_file["item_type"].get<int>(), parsed_file["item_lvl"].get<int>(), parsed_file["item_name"].get<std::string>(),
            parsed_file["item_condition"].get<int>(), parsed_file["healing"].get<int>(), parsed_file["charges"].get<int>(), parsed_file["heal_type"].get<int>()));

    }
}
void GameContent::loadData_Armoury()
{


    //---filenames container
    std::set<std::filesystem::path> armour_sorted_by_name;

    //---inserting file names into set
    for (auto& entry : std::filesystem::directory_iterator(items_pathlist[2]))
        armour_sorted_by_name.insert(entry.path());

    std::ifstream file_input;
    std::string serialised_data;//raw_data
    std::string temp;//temp data from loop
    char* ptr = NULL;
    for (auto& filename : armour_sorted_by_name)
    {
        file_input.open(filename, std::ifstream::app, std::ifstream::binary);

        while (!file_input.eof())
        {
            ptr = new char[36];
            file_input.getline(ptr, 35, '\n');
            serialised_data += ptr;
            delete[]ptr;
        }
        std::cout << serialised_data << "\n\n";
        file_input.close();
        json parsed_file = json::parse(serialised_data);
        serialised_data = "";
        ad_content::armour_data.push_back(Game_Armour(parsed_file["item_id"].get<int>(), parsed_file["cost"].get<int>(), parsed_file["rarity"].get<int>(), parsed_file["item_type"].get<int>(), parsed_file["item_lvl"].get<int>(), parsed_file["item_name"].get<std::string>(),
            parsed_file["armour_type"].get<int>(),parsed_file["armour"].get<int>(), parsed_file["evasion"].get<int>(), parsed_file["item_condition"].get<int>()));

    }
}

void GameContent::loadData_Loot()
{
    //---filenames container
    std::set<std::filesystem::path> loot_sorted_by_name;

    //---inserting file names into set
    for (auto& entry : std::filesystem::directory_iterator(items_pathlist[0]))
        loot_sorted_by_name.insert(entry.path());

    std::ifstream file_input;
    std::string serialised_data;//raw_data
    std::string temp;//temp data from loop
    char* ptr = NULL;
    for (auto& filename : loot_sorted_by_name)
    {
        file_input.open(filename, std::ifstream::app, std::ifstream::binary);

        while (!file_input.eof())
        {
            ptr = new char[36];
            file_input.getline(ptr, 35, '\n');
            serialised_data += ptr;
            delete[]ptr;
        }
        std::cout << serialised_data << "\n\n";
        file_input.close();
        json parsed_file = json::parse(serialised_data);
        serialised_data = "";
        ad_content::loot_data.push_back(Game_Loot(parsed_file["item_id"].get<int>(), parsed_file["cost"].get<int>(), parsed_file["rarity"].get<int>(), parsed_file["item_type"].get<int>(), parsed_file["item_lvl"].get<int>(), parsed_file["item_name"].get<std::string>(),
            parsed_file["item_condition"].get<int>()));

    }
}


/* static const int WeaponDataSIZE = 9;
	//---counting files

    auto dirIter = std::filesystem::directory_iterator(pathlist[1]);
    int fileCount = 0;

    for (auto& entry : dirIter)
    {
        if (entry.is_regular_file())
        {
            ++fileCount;
        }
    }

    //---allocating memory for data
    // 
    std::set<std::filesystem::path> weapon_sorted_by_name;
    //---inserting file names into set
    for (auto& entry : std::filesystem::directory_iterator(pathlist[1]))
        weapon_sorted_by_name.insert(entry.path());
    std::ifstream fout;
    char* temp_stringdata;
    int i = 0; int item_i = 0;
    std::string* tempry_data = new std::string[WeaponDataSIZE];
    for (auto& filename : weapon_sorted_by_name)
    { 
        fout.open(filename);
        
        while (!fout.eof())
        {
            temp_stringdata = new char[25];
            fout.getline(temp_stringdata, 25, '\n');
            //здесь заносить всю информацию о предмете в массив
            tempry_data[i] = temp_stringdata;
            i++;
            delete []temp_stringdata;
            if(fout.eof())
                i = 0;
        }
        weapons_data.push_back(Game_Weapon(std::stoi(tempry_data[8]), std::stoi(tempry_data[0]), std::stoi(tempry_data[1]), std::stoi(tempry_data[2]), std::stoi(tempry_data[3]), tempry_data[4], std::stoi(tempry_data[5]), std::stoi(tempry_data[6]), std::stoi(tempry_data[7])));
        fout.close();
        item_i++;
    }
    delete[]tempry_data;
    std::cout << weapons_data.size() << std::endl;*/
