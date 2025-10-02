# MacroMind

**MacroMind** is a C++ command-line nutrition tracker designed to help users manage their daily food intake, calculate macros, and optimize nutrition per dollar spent. It’s built for efficiency and simplicity, using object-oriented design to handle foods, recipes, and macro goals.

---

## Features

- Track daily meals and nutrition intake  
- Manage a database of foods with macros and costs  
- Calculate total calories, protein, carbs, and fats per day  
- Optimize meals for nutrition and budget  
- Lightweight and easy to run from the command line  

---

## Installation & Setup

1. **Clone the repository:**

```bash
git clone https://github.com/bilalsalman0815/MacroMind.git
Open in CLion:
Open CLion → File → Open → select the MacroMind folder.

Build the project:
CLion will automatically handle CMake and compile the project.

Run the program:
Run the macroMind.cpp file from CLion or your terminal.

Project Structure
macroMind.cpp → Main program driver

Food.cpp / Food.h → Food object class

FoodDatabase.cpp / FoodDatabase.h → Handles food database

MacroGoals.cpp / MacroGoals.h → Stores daily macro goals

DailyLog.cpp / DailyLog.h → Tracks daily food intake

foods.csv → Example food database

.gitignore → Ignores build files, IDE files, and temporary files

Notes
CLion build directories and binaries are ignored via .gitignore

Only essential code files are included in this repo

Designed for cross-platform compilation via CMake
