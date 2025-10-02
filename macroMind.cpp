#include "Food.h"
#include "FoodDatabase.h"
#include "DailyLog.h"
#include "MacroGoals.h"
#include <limits>

int main()
{
    // Variables
    double weight = 0.0;
    std::string activity_level;
    std::string goal;
    std::string date;
    std::string user_menu_choice;
    std::string food_name;
    double calories = 0, protein = 0, carbs = 0, fats = 0, cost_per_serving = 0;
    double servings = 0;

    // Welcome message and setup
    std::cout << "\nWelcome to MacroMind!" << std::endl;
    std::cout << "\nPlease enter your weight in pounds: ";
    std::cin >> weight;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Please enter your activity level (active, moderate, or sedentary): ";
    std::cin >> activity_level;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Please enter your goal (bulk, cut, maintain): ";
    std::cin >> goal;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Please enter today's date (MM/DD/YYYY): ";
    std::cin >> date;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    //Load database
    Food_database *database = new Food_database;
    database->load_from_file("../foods.csv");

    // Create daily log
    Daily_log *today_log = new Daily_log(date);

    // Create goals;
    Macro_goals *goals = new Macro_goals(weight, activity_level, goal);

    // Main menu loop
    do
    {
        std::cout << "\n============= MacroMind Nutrition Tracker =============\n";
        std::cout << "1. Food Database Management\n";
        std::cout << "   a. View all foods\n";
        std::cout << "   b. Add new food\n";
        std::cout << "   c. Remove food\n";
        std::cout << "   d. Search foods\n";
        std::cout << "2. View Macro Goals\n";
        std::cout << "3. Today's Food Log\n";
        std::cout << "   a. Add food entry\n";
        std::cout << "   b. View detailed log\n";
        std::cout << "   c. View daily summary\n";
        std::cout << "4. Compare to Goals\n";
        std::cout << "5. Save and Exit\n";
        std::cout << "========================================================\n";
        std::cout << "Please enter your choice with the corresponding letter and number if applicable: ";
        std::cin >> user_menu_choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if(user_menu_choice == "1a")
        {
            database->list_all_foods();
            std::cout << "\nPress Enter to return to main menu...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if(user_menu_choice == "1b")
        {
            Food temp_food;

            std::cout << "\nPlease enter the name of the food you want to add: ";
            std::getline(std::cin, food_name);

            std::cout << "Please enter the number of calories: ";
            std::cin >> calories;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Please enter the number of grams of protein: ";
            std::cin >> protein;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Please enter the number of grams of carbs: ";
            std::cin >> carbs;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Please enter the number of grams of fats: ";
            std::cin >> fats;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Please enter the cost per serving: ";
            std::cin >> cost_per_serving;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            temp_food.set_name(food_name);
            temp_food.set_calories(calories);
            temp_food.set_protein(protein);
            temp_food.set_carbs(carbs);
            temp_food.set_fats(fats);
            temp_food.set_cost_per_serving(cost_per_serving);
            database->add_food(temp_food);

            std::cout << "\nThe food has successfully been added to the database!\n";
            std::cout << "\nPress Enter to return to main menu...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if(user_menu_choice == "1c")
        {
            std::cout << "Please enter the name of the food you want to remove: ";
            food_name = "";
            std::getline(std::cin, food_name);
            database->remove_food(food_name);

            std::cout << "\nThe food has successfully been removed from the database!\n";
            std::cout << "\nPress Enter to return to main menu...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if(user_menu_choice == "1d")
        {
            std::cout << "\nPlease enter a keyword to search for foods: ";
            food_name = "";
            std::getline(std::cin, food_name);
            std::vector<Food> search = database->search_foods(food_name);

            for(int i = 0; i < search.size(); i++)
            {
                std::cout << search[i].to_string() << std::endl;
            }
            std::cout << "\nPress Enter to return to main menu...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if(user_menu_choice == "2")
        {
            std::cout << "\n========== My Macro Goals ==========\n";
            std::cout << "Weight: " << weight << " lbs\n";
            std::cout << "Activity Level: " << activity_level << "\n";
            std::cout << "Goal: " << goal << "\n";
            std::cout << "------------------------------------\n";
            std::cout << "Calorie Target: " << goals->get_calorie_target() << " cal\n";
            std::cout << "Protein Target: " << goals->get_protein_target() << "g\n";
            std::cout << "Carb Target: " << goals->get_carb_target() << "g\n";
            std::cout << "Fat Target: " << goals->get_fat_target() << "g\n";
            std::cout << "====================================\n";

            std::cout << "\nPress Enter to return to main menu...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if(user_menu_choice == "3a")
        {
            Food_entry entry;

            std::cout << "\nPlease enter the name of the food you want to add: ";
            food_name = "";
            std::getline(std::cin, food_name);

            std::cout << "Please enter the number of calories: ";
            calories = 0;
            std::cin >> calories;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Please enter the number of grams of protein: ";
            protein = 0;
            std::cin >> protein;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Please enter the number of grams of carbs: ";
            carbs = 0;
            std::cin >> carbs;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Please enter the number of grams of fats: ";
            fats = 0;
            std::cin >> fats;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Please enter the cost per serving: ";
            cost_per_serving = 0;
            std::cin >> cost_per_serving;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Please enter the number of servings: ";
            servings = 0;
            std::cin >> servings;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // set all food details
            entry.food.set_name(food_name);
            entry.food.set_calories(calories);
            entry.food.set_protein(protein);
            entry.food.set_carbs(carbs);
            entry.food.set_fats(fats);
            entry.food.set_cost_per_serving(cost_per_serving);
            entry.servings = servings;

            today_log->add_entry(entry.food, entry.servings);

            std::cout << "\nFood entry added to today's log!\n";

            std::cout << "\nPress Enter to return to main menu...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        }
        else if(user_menu_choice == "3b")
        {
            today_log->display_detailed_log();

            std::cout << "\nPress Enter to return to main menu...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if(user_menu_choice == "3c")
        {
            today_log->display_summary();

            std::cout << "\nPress Enter to return to main menu...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if(user_menu_choice == "4")
        {
            goals->compare_to_log(*today_log);

            std::cout << "\nPress Enter to return to main menu...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    while(user_menu_choice != "5");

    database->save_to_file("../foods.csv");
    std::cout << "\nThanks for using MacroMind!" << std::endl;
    delete database;
    delete today_log;
    delete goals;
    return 0;
}
