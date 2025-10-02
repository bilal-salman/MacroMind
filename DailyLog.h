#ifndef MACROMIND_DAILYLOG_H
#define MACROMIND_DAILYLOG_H

#include "Food.h"
#include "string"
#include <vector>
#include "iostream"
#include "iomanip"
#include <sstream>

struct Food_entry
{
    Food food;
    double servings;
};

class Daily_log
{
private:
    std::string date;
    std::vector<Food_entry> entries;

public:
    Daily_log(std::string date);
    void add_entry(Food food, double servings);
    std::string get_date() const;
    int get_total_calories() const;
    double get_total_protein() const;
    double get_total_carbs() const;
    double get_total_fats() const;
    double get_total_cost() const;
    void display_summary() const;
    void display_detailed_log() const;
};

#endif //MACROMIND_DAILYLOG_H
