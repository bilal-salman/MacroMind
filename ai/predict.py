import pandas as pd
from sklearn.linear_model import LinearRegression
import os

# Get folder of this script
script_dir = os.path.dirname(__file__)

# Build full paths relative to the script
daily_progress_file = os.path.join(script_dir, "../data/daily_progress.csv")
prediction_file = os.path.join(script_dir, "../data/prediction.txt")

# Load CSV file
data = pd.read_csv(daily_progress_file)

# Features = inputs for prediction
X = data[['calories', 'protein', 'carbs', 'fats']]

# Target = what we want to predict
y = data['weight']

# Create model
model = LinearRegression()

# Train the model on the historical data
model.fit(X, y)

# Take the most recent day’s intake
latest_intake = X.tail(1)  

# Predict weight
prediction = model.predict(latest_intake)

# Save prediction
with open(prediction_file, "w") as f:
    f.write(f"Predicted weight for tomorrow: {prediction[0]:.2f} lbs\n")