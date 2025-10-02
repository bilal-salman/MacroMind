cmake_minimum_required(VERSION 3.26)
project(MacroMind)

set(CMAKE_CXX_STANDARD 20)

# Food Database Driver
add_executable(foodDatabaseDriver
        Food.cpp Food.h
        FoodDatabase.cpp FoodDatabase.h
        foodDatabaseDriver.cpp)

# Daily Tracking Driver
add_executable(dailyTrackingDriver
        Food.cpp Food.h
        FoodDatabase.cpp FoodDatabase.h
        DailyLog.cpp DailyLog.h
        MacroGoals.cpp MacroGoals.h
        dailyTrackingDriver.cpp)

# Main Application
add_executable(macroMind
        Food.cpp Food.h
        FoodDatabase.cpp FoodDatabase.h
        DailyLog.cpp DailyLog.h
        MacroGoals.cpp MacroGoals.h
        macroMind.cpp)