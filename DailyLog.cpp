#include "DailyLog.h"

Daily_log::Daily_log(std::string date)
{
    this->date = date;
}

void Daily_log::add_entry(Food food, double servings)
{
    Food_entry temp_entry;
    temp_entry.food = food;
    temp_entry.servings = servings;

    entries.push_back(temp_entry);
}

std::string Daily_log::get_date() const
{
    return this->date;
}

int Daily_log::get_total_calories() const
{
    int total_calories = 0;

    for(int i = 0; i < entries.size(); i++)
    {
        total_calories += entries[i].food.get_calories() * entries[i].servings;
    }

    return  total_calories;
}

double Daily_log::get_total_protein() const
{
    double total_protein = 0.0;

    for(int i = 0; i < entries.size(); i++)
    {
        total_protein += entries[i].food.get_protein() * entries[i].servings;
    }

    return total_protein;
}

double Daily_log::get_total_carbs() const
{
    double total_carbs = 0.0;

    for(int i = 0; i < entries.size(); i++)
    {
        total_carbs += entries[i].food.get_carbs() * entries[i].servings;
    }

    return total_carbs;
}

double Daily_log::get_total_fats() const
{
    double total_fats = 0.0;

    for(int i = 0; i < entries.size(); i++)
    {
        total_fats += entries[i].food.get_fats() * entries[i].servings;
    }

    return total_fats;
}

double Daily_log::get_total_cost() const
{
    double total_cost = 0.0;

    for(int i = 0; i < entries.size(); i++)
    {
        total_cost += entries[i].food.get_cost_per_serving() * entries[i].servings;
    }

    return total_cost;
}

void Daily_log::display_summary() const
{
    std::cout << "\n==================== Daily Summary ====================\n";
    std::cout << "Date: " << date << "\n";
    std::cout << std::string(55, '-') << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Total Calories:  " << get_total_calories() << " cal\n";
    std::cout << "Total Protein:   " << get_total_protein() << "g\n";
    std::cout << "Total Carbs:     " << get_total_carbs() << "g\n";
    std::cout << "Total Fats:      " << get_total_fats() << "g\n";

    std::cout << std::setprecision(2);
    std::cout << "Total Cost:      $" << get_total_cost() << "\n";
    std::cout << "=======================================================\n";
}

void Daily_log::display_detailed_log() const
{
    std::cout << "\n================================== Daily Log: " << date << " =================================\n";
    std::cout << std::left << std::setw(30) << "Food"
              << std::right << std::setw(12) << "Servings"
              << std::setw(12) << "Calories"
              << std::setw(12) << "Protein(g)"
              << std::setw(12) << "Carbs(g)"
              << std::setw(12) << "Fats(g)" << std::endl;
    std::cout << std::string(90, '-') << std::endl;

    for(int i = 0; i < entries.size(); i++)
    {
        std::cout << std::left << std::setw(30) << entries[i].food.get_name()
                  << std::right << std::setw(12) << std::fixed << std::setprecision(1)
                  << entries[i].servings
                  << std::setw(12) << (int)(entries[i].food.get_calories() * entries[i].servings)
                  << std::setw(12) << entries[i].food.get_protein() * entries[i].servings
                  << std::setw(12) << entries[i].food.get_carbs() * entries[i].servings
                  << std::setw(12) << entries[i].food.get_fats() * entries[i].servings
                  << std::endl;
    }
    std::cout << std::string(90, '=') << std::endl;
}