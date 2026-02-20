# MacroMind – Personalized Nutrition & Weight Tracker

**MacroMind** is a nutrition and fitness tracking system that helps users log daily food intake, track macro goals, and receive simple predictive insights. It combines **C++** for the interactive interface with **Python** scripts for weight prediction and personalized advice.

## Features

### Daily Tracking (C++)
- Log weight, activity level, goals (cut, bulk, maintain), and foods.
- View summaries and breakdowns of calories, protein, carbs, and fats.

### Macro Goal Comparison (C++)
- Calculates individualized macro targets.
- Compares intake to targets and provides immediate feedback.

### Weight Prediction (Python)
- Uses linear regression to forecast next-day weight based on historical logs.

### Nutrition Advice (Python)
- Generates actionable tips on protein, carbs, fats, and total calories.
- Reads past logs and outputs recommendations for integration with the C++ interface.

## How It Works
1. Users interact with the **C++ console interface** for logging and tracking.
2. Python scripts (`predict.py` and `coach.py`) analyze historical logs and generate predictions and advice.
3. Communication between C++ and Python is handled via CSV and TXT files.
