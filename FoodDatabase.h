#ifndef MACROMIND_FOODDATABASE_H
#define MACROMIND_FOODDATABASE_H

#include "Food.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <cctype>

class Food_database
{
private:
    std::vector<Food> foods;

public:
    Food_database() = default;
    void load_from_file(std::string filename);
    void save_to_file(std::string filename);
    void add_food(Food food);
    void remove_food(std::string name);
    Food* getFood(std::string name);
    void list_all_foods() const;
    std::vector<Food> search_foods(std::string keyword) const;
};


#endif //MACROMIND_FOODDATABASE_H
