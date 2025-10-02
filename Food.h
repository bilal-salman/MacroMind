#ifndef MACROMIND_FOOD_H
#define MACROMIND_FOOD_H

#include "string"


class Food
{
private:
    std::string name;
    int calories;
    double protein;
    double carbs;
    double fats;
    double cost_per_serving;

public:
    Food() = default;
    Food(std::string name, int calories, double protein, double carbs, double fats, double cost_per_serving);
    std::string to_string() const;

    // Getters
    std::string get_name() const;
    int get_calories() const;
    double get_protein() const;
    double get_carbs() const;
    double get_fats() const;
    double get_cost_per_serving() const;
    double get_protein_per_dollar() const;
    double get_calories_per_dollar() const;

    // Setters
    void set_name(std::string name);
    void set_calories(int calories);
    void set_protein(double protein);
    void set_carbs(double carbs);
    void set_fats(double fats);
    void set_cost_per_serving(double cost);
};


#endif //MACROMIND_FOOD_H
