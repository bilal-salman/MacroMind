#include "Food.h"
#include <sstream>
#include <iomanip>

Food::Food(std::string name, int calories, double protein, double carbs, double fats, double cost_per_serving)
{
    this->name = name;
    this->calories = calories;
    this->protein = protein;
    this->carbs = carbs;
    this->fats = fats;
    this->cost_per_serving = cost_per_serving;
}

std::string Food::to_string() const
{
    std::ostringstream formatted_string;

    formatted_string << name << "\t\t" << std::fixed << std::setprecision(1) << calories << " cal" << "\t\t"
    << protein << "g protein" << "\t\t" << carbs << "g carbs" << "\t\t" << fats << "g fats" << "\t\t"
    << "$" << std::setprecision(2) << cost_per_serving << " per serving";

    return  formatted_string.str();
}

std::string Food::get_name() const
{
    return this->name;
}

int Food::get_calories() const
{
   return this->calories;
}

double Food::get_protein() const
{
    return this->protein;
}

double Food::get_carbs() const
{
    return this->carbs;
}

double Food::get_fats() const
{
    return this->fats;
}

double Food::get_cost_per_serving() const
{
    return this->cost_per_serving;
}

double Food::get_protein_per_dollar() const
{
    if(cost_per_serving > 0)
    {
        return (protein / cost_per_serving);
    }
    else
    {
        return 0.0;
    }
}

double Food::get_calories_per_dollar() const
{
    if(cost_per_serving > 0)
    {
        return (calories / cost_per_serving);
    }
    else
    {
        return 0.0;
    }
}

void Food::set_name(std::string name)
{
    this->name = name;
}

void Food::set_calories(int calories)
{
    this->calories = calories;
}

void Food::set_protein(double protein)
{
    this->protein = protein;
}

void Food::set_carbs(double carbs)
{
    this->carbs = carbs;
}

void Food::set_fats(double fats)
{
    this->fats = fats;
}

void Food::set_cost_per_serving(double cost)
{
    this->cost_per_serving = cost;
}