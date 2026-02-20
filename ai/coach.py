import os
import sys
import pandas as pd

# Paths
script_dir = os.path.dirname(os.path.abspath(__file__))
data_dir = os.path.join(script_dir, "../data")
progress_file = os.path.join(data_dir, "daily_progress.csv")
prediction_file = os.path.join(data_dir, "prediction.txt")
advice_file = os.path.join(data_dir, "advice.txt")

# Get user goal
goal = sys.argv[1].lower() if len(sys.argv) > 1 else "maintain"

# Read latest macros
df = pd.read_csv(progress_file)
latest = df.iloc[-1]
calories = latest['calories']
protein = latest['protein']
carbs = latest['carbs']
fats = latest['fats']

# Read predicted weight
with open(prediction_file, "r") as f:
    line = f.readline().strip()
    predicted_weight = float(line.split(":")[1].split()[0])

# Micro AI logic: simple rule-based tips
tips = []

# Tip 1: Protein check
if protein < 100:
    tips.append("Increase protein intake to support satiety and muscle retention.")
else:
    tips.append("Protein intake is adequate for your goal.")

# Tip 2: Carb adjustment based on goal
if goal == "cut":
    if carbs > 150:
        tips.append("Consider lowering carbs slightly to stay in a caloric deficit.")
    else:
        tips.append("Carb intake is reasonable for cutting.")
elif goal == "bulk":
    tips.append("Ensure carbs support your energy needs for muscle growth.")

# Tip 3: Fat and calorie check
if fats < 30:
    tips.append("Add healthy fats (nuts, avocado) to balance macros.")
elif calories > 2500 and goal == "cut":
    tips.append("Monitor total calories; consider reducing portion sizes.")

# Save to file
with open(advice_file, "w") as f:
    for t in tips:
        f.write(f"- {t}\n")