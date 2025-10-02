#include "FoodDatabase.h"

void Food_database::load_from_file(std::string filename)
{
    std::ifstream input_file;
    input_file.open(filename);

    if(input_file.is_open())
    {
        Food temp_food; // Temp object to hold data
        std::string temp_line; // Hold each line
        std::string name, calories, protein, carbs, fats, cost; // Temp variables to hold each data point

        while(std::getline(input_file,temp_line))
        {
            std::istringstream comma(temp_line);

            std::getline(comma,name,',');
            temp_food.set_name(name);

            std::getline(comma,calories,',');
            temp_food.set_calories(std::stoi(calories));

            std::getline(comma,protein,',');
            temp_food.set_protein(std::stod(protein));

            std::getline(comma,carbs,',');
            temp_food.set_carbs(std::stod(carbs));

            std::getline(comma,fats,',');
            temp_food.set_fats(std::stod(fats));

            std::getline(comma,cost,',');
            temp_food.set_cost_per_serving(std::stod(cost));

            foods.push_back(temp_food);
        }

        input_file.close();
    }
    else
    {
        std::cout << "\nFile failed to open!" << std::endl;
        exit(1);
    }
}

void Food_database::save_to_file(std::string filename)
{
    std::ofstream output_file;
    output_file.open(filename);

    if(output_file.is_open())
    {
        for(int i = 0; i < foods.size(); i++)
        {
            output_file << foods[i].get_name() << "," << foods[i].get_calories() << "," << foods[i].get_protein()
                        << "," << foods[i].get_carbs() << "," << foods[i].get_fats() <<  ","
                        << foods[i].get_cost_per_serving() << std::endl;
        }

        output_file.close();
        std::cout << "\nSuccessfully saved food data to file!" << std::endl;
    }
    else
    {
        std::cout << "\nFile failed to open!" << std::endl;
        exit(1);
    }
}

void Food_database::add_food(Food food)
{
    foods.push_back(food);
}

void Food_database::remove_food(std::string name)
{
    for(int i = 0; i < foods.size(); i++)
    {
        if(foods[i].get_name() == name)
        {
            foods.erase(foods.begin() + i);
        }
    }
}

Food* Food_database::getFood(std::string name)
{
    for(int i = 0; i < foods.size(); i++)
    {
        if(foods[i].get_name() == name)
        {
            return &foods[i];
        }
    }
    return nullptr;
}

void Food_database::list_all_foods() const
{
    std::cout << "\n==================================== Food Database =======================================\n" << std::endl;
    std::cout << std::left << std::setw(30) << "Name"
              << std::right << std::setw(12) << "Calories"
              << std::setw(12) << "Protein(g)"
              << std::setw(12) << "Carbs(g)"
              << std::setw(12) << "Fats(g)"
              << std::setw(12) << "Cost($)" << std::endl;
    std::cout << std::string(90, '-') << std::endl;

    for(int i = 0; i < foods.size(); i++)
    {
        std::cout << std::left << std::setw(30) << foods[i].get_name()
                  << std::right << std::setw(12) << foods[i].get_calories()
                  << std::setw(12) << std::fixed << std::setprecision(1) << foods[i].get_protein()
                  << std::setw(12) << foods[i].get_carbs()
                  << std::setw(12) << foods[i].get_fats()
                  << std::setw(12) << std::setprecision(2) << foods[i].get_cost_per_serving()
                  << std::endl;
    }
    std::cout << "\nTotal foods: " << foods.size() << std::endl;
    std::cout << "==========================================================================================\n";
}

std::vector<Food> Food_database::search_foods(std::string keyword) const
{
    std::vector<Food> results;

    std::string lower_keyword = keyword;
    std::transform(lower_keyword.begin(), lower_keyword.end(), lower_keyword.begin(), ::tolower);

    for(int i = 0; i < foods.size(); i++)
    {
        std::string lower_name = foods[i].get_name();
        std::transform(lower_name.begin(), lower_name.end(), lower_name.begin(), ::tolower);

        if(lower_name.find(lower_keyword) != std::string::npos)
        {
            results.push_back(foods[i]);
        }
    }

    return results;
}
