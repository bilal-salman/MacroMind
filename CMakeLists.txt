cmake_minimum_required(VERSION 3.26)
project(MacroMind)

set(CMAKE_CXX_STANDARD 20)

# Main Application
add_executable(macroMind
    src/Food.cpp
    src/FoodDatabase.cpp
    src/DailyLog.cpp
    src/MacroGoals.cpp
    src/macroMind.cpp
)
