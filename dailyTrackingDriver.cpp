#include "iostream"
#include "FoodDatabase.h"
#include "DailyLog.h"
#include "MacroGoals.h"

int main()
{
    // Load food database
    Food_database database;
    database.load_from_file("../foods.csv");

    // Create macro goals (180 lbs, moderate activity, bulking)
    Macro_goals my_goals(180, "moderate", "bulk");

    std::cout << "\n========== My Macro Goals ==========\n";
    std::cout << "Weight: 180 lbs\n";
    std::cout << "Activity Level: Moderate\n";
    std::cout << "Goal: Bulk\n";
    std::cout << "------------------------------------\n";
    std::cout << "Calorie Target: " << my_goals.get_calorie_target() << " cal\n";
    std::cout << "Protein Target: " << my_goals.get_protein_target() << "g\n";
    std::cout << "Carb Target: " << my_goals.get_carb_target() << "g\n";
    std::cout << "Fat Target: " << my_goals.get_fat_target() << "g\n";
    std::cout << "====================================\n";

    // Create a daily log for today
    Daily_log today("10/01/2025");

    // Add food entries
    Food* chicken = database.getFood("Chicken Breast");
    if(chicken != nullptr) {
        today.add_entry(*chicken, 2.5);
    }

    Food* rice = database.getFood("Brown Rice");
    if(rice != nullptr) {
        today.add_entry(*rice, 2.0);
    }

    Food* eggs = database.getFood("Eggs");
    if(eggs != nullptr) {
        today.add_entry(*eggs, 4.0);
    }

    Food* oats = database.getFood("Oats");
    if(oats != nullptr) {
        today.add_entry(*oats, 1.5);
    }

    Food* banana = database.getFood("Banana");
    if(banana != nullptr) {
        today.add_entry(*banana, 2.0);
    }

    Food* peanut_butter = database.getFood("Peanut Butter");
    if(peanut_butter != nullptr) {
        today.add_entry(*peanut_butter, 2.0);
    }

    // Display detailed log and summary
    today.display_detailed_log();
    today.display_summary();

    // Compare actual intake to goals
    my_goals.compare_to_log(today);

    return 0;
}