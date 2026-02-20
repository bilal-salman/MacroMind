#include "MacroGoals.h"

Macro_goals::Macro_goals(double weight, std::string activity_level, std::string goal)
{
    this->weight = weight;
    this->activity_level = activity_level;
    this->goal = goal;
}

int Macro_goals::get_calorie_target() const
{
    if(goal == "maintain")
    {
        if(activity_level == "sedentary")
        {
            return static_cast<int>(weight * 14);
        }
        else if(activity_level == "moderate")
        {
            return static_cast<int>(weight * 16);
        }
        else if(activity_level == "active")
        {
            return static_cast<int>(weight * 18);
        }
        else
        {
            return 0;
        }
    }
   else if(goal == "cut")
   {
       if(activity_level == "sedentary")
       {
           return static_cast<int>(weight * 14) - 500;
       }
       else if(activity_level == "moderate")
       {
           return static_cast<int>(weight * 16) - 500;
       }
       else if(activity_level == "active")
       {
           return static_cast<int>(weight * 18) - 500;
       }
       else
       {
           return 0;
       }
   }
    else if(goal == "bulk")
    {
        if(activity_level == "sedentary")
        {
            return static_cast<int>(weight * 14) + 300;
        }
        else if(activity_level == "moderate")
        {
            return static_cast<int>(weight * 16) + 300;
        }
        else if(activity_level == "active")
        {
            return static_cast<int>(weight * 18) + 300;
        }
        else
        {
            return 0;
        }
    }
}

int Macro_goals::get_protein_target() const
{
    if(goal == "bulk")
    {
        return static_cast<int>(weight * 1.0);
    }
    else if(goal == "cut")
    {
        return static_cast<int>(weight * 0.9);
    }
    else if(goal == "maintain")
    {
        return static_cast<int>(weight * 0.8);
    }
    else
    {
        return 0;
    }
}

int Macro_goals::get_fat_target() const
{
    return static_cast<int>(get_calorie_target() * 0.25) / 9;
}

int Macro_goals::get_carb_target() const
{
    return (get_calorie_target() - (get_protein_target() * 4) - (get_fat_target() * 9)) / 4;
}

void Macro_goals::compare_to_log(Daily_log &log) const
{
    std::stringstream ss; // Used to format strings before printing

    std::cout << "\n======================== Goals vs Actual ========================\n";
    std::cout << std::left << std::setw(20) << ""
              << std::right << std::setw(15) << "Target"
              << std::setw(15) << "Actual"
              << std::setw(15) << "Difference" << std::endl;
    std::cout << std::string(65, '-') << std::endl;

    // --- Calories ---
    int calorie_diff = log.get_total_calories() - get_calorie_target();
    ss.str(""); // Clear the stream
    if (calorie_diff >= 0) ss << "+";
    ss << calorie_diff;
    std::cout << std::left << std::setw(20) << "Calories:"
              << std::right << std::setw(15) << get_calorie_target()
              << std::setw(15) << log.get_total_calories()
              << std::setw(15) << ss.str() << std::endl; // FIXED

    // --- Protein ---
    double protein_diff = log.get_total_protein() - get_protein_target();
    std::cout << std::fixed << std::setprecision(1);
    ss.str(""); ss << get_protein_target() << "g";
    std::cout << std::left << std::setw(20) << "Protein:"
              << std::right << std::setw(15) << ss.str(); // FIXED
    ss.str(""); ss << log.get_total_protein() << "g";
    std::cout << std::setw(15) << ss.str(); // FIXED
    ss.str(""); if (protein_diff >= 0) ss << "+"; ss << protein_diff << "g";
    std::cout << std::setw(15) << ss.str() << std::endl; // FIXED

    // --- Carbs ---
    double carb_diff = log.get_total_carbs() - get_carb_target();
    ss.str(""); ss << get_carb_target() << "g";
    std::cout << std::left << std::setw(20) << "Carbs:"
              << std::right << std::setw(15) << ss.str(); // FIXED
    ss.str(""); ss << log.get_total_carbs() << "g";
    std::cout << std::setw(15) << ss.str(); // FIXED
    ss.str(""); if (carb_diff >= 0) ss << "+"; ss << carb_diff << "g";
    std::cout << std::setw(15) << ss.str() << std::endl; // FIXED

    // --- Fats ---
    double fat_diff = log.get_total_fats() - get_fat_target();
    ss.str(""); ss << get_fat_target() << "g";
    std::cout << std::left << std::setw(20) << "Fats:"
              << std::right << std::setw(15) << ss.str(); // FIXED
    ss.str(""); ss << log.get_total_fats() << "g";
    std::cout << std::setw(15) << ss.str(); // FIXED
    ss.str(""); if (fat_diff >= 0) ss << "+"; ss << fat_diff << "g";
    std::cout << std::setw(15) << ss.str() << std::endl; // FIXED

    std::cout << "=================================================================\n";
}