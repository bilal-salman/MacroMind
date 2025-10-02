#include "Food.h"
#include "FoodDatabase.h"

int main()
{
    // Testing
    Food_database *database = new Food_database;
    database->load_from_file("../foods.csv");
    Food *burger = new Food("Burger", 400, 20, 50, 25, 9);
    database->add_food(*burger);
    database->remove_food("Ground Beef 80/20");
    Food *searched = database->getFood("Oats");
    std::cout << searched->get_name();
    database->list_all_foods();

    std::vector<Food> search = database->search_foods("Rice");
    for(int i = 0; i < search.size(); i++)
    {
        std::cout << search[i].to_string() << std::endl;
    }

    database->save_to_file("../foods.csv");

    searched = nullptr;
    delete database;
    delete burger;
    return 0;
}

