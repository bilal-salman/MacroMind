# MacroMind

**MacroMind** is a C++ command-line nutrition tracker designed to help users manage their daily food intake, calculate macros, and optimize nutrition per dollar spent. It’s built for efficiency and simplicity, using object-oriented design to handle foods, recipes, and macro goals.

-----

## Features

  - Track daily meals and nutrition intake
  - Manage a database of foods with macros and costs
  - Calculate total calories, protein, carbs, and fats per day
  - Optimize meals for nutrition and budget
  - Lightweight and easy to run from the command line

-----

## Installation & Setup

### Option 1: Using CLion (Recommended)

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/bilalsalman0815/MacroMind.git
    ```
2.  **Open in CLion:**
      - Open CLion → `File` → `Open` → select the `MacroMind` folder.
3.  **Build the project:**
      - CLion will automatically handle CMake and compile the project.
4.  **Run the program:**
      - Run the `macroMind.cpp` file from within CLion.

### Option 2: Using Terminal (No IDE Required)

1.  **Prerequisites:**
      - Make sure you have a C++ compiler (like GCC or Clang) and `CMake` installed on your system.
2.  **Clone the repository and enter the directory:**
    ```bash
    git clone https://github.com/bilalsalman0815/MacroMind.git
    cd MacroMind
    ```
3.  **Create a build directory:**
    ```bash
    mkdir build
    cd build
    ```
4.  **Generate build files with CMake:**
    ```bash
    cmake ..
    ```
5.  **Compile the project:**
    ```bash
    cmake --build .
    ```
6.  **Run the program:**
    ```bash
    # On macOS/Linux
    ./MacroMind

    # On Windows
    .\MacroMind.exe
    ```

-----
