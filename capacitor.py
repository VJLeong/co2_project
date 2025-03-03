import serial
import time
from tqdm import tqdm
import numpy as np
import matplotlib.pyplot as plt
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler

# Serial connection setup (Please check Device Manager to check your COM port and baud rate set from PSoC Creator)
ser = serial.Serial('COM3', 57600, timeout=1)

start_time = time.time()
duration = 600  # Collect data for 10 minutes
tolerance = 10

capacitances = []

# Data collection loop
with tqdm(total=duration, desc="Collecting Data", bar_format="{l_bar}{bar} {n_fmt}/{total_fmt}s") as pbar:
    while time.time() - start_time < duration:
        if ser.in_waiting > 0:
            data = ser.readline().decode('utf-8').strip()
            try:
                if "Capacitance:" in data and "nF" in data:
                    capacitance = float(data.split("Capacitance: ")[1].split(" nF")[0])
                    capacitances.append(capacitance)
                else:
                    print(f"Skipping invalid data: {data}")

            except (IndexError, ValueError):
                print(f"Error parsing data: {data}")

        # Update progress bar
        elapsed_time = time.time() - start_time
        pbar.update(min(elapsed_time - pbar.n, 1))  # Ensure we don't overshoot progress

ser.close()  # Close serial connection after data collection

if len(capacitances) == 0:
    print("No valid capacitance data received. Exiting.")
    exit()

# Prepare labels for machine learning
capacitances = np.array(capacitances).reshape(-1, 1)
labels = np.where((capacitances >= 100 - tolerance) & (capacitances <= 100 + tolerance), "100nF", "Other")

# Train-test split
X_train, X_test, Y_train, Y_test = train_test_split(capacitances, labels, test_size=0.2, random_state=69)

# Standardize data
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

# Train KNN Model
knn = KNeighborsClassifier(n_neighbors=3)
knn.fit(X_train, Y_train)

# Reopen serial for real-time classification
ser = serial.Serial('COM3', 57600, timeout=1)

plt.ion()  # Enable interactive mode
fig, ax = plt.subplots()
data_points = []
labels_list = []
start_time = time.time()

try:
    with tqdm(total=duration, desc="Collecting & Predicting", bar_format="{l_bar}{bar} {n_fmt}/{total_fmt}s") as pbar:
        while time.time() - start_time < duration:
            if ser.in_waiting > 0:
                data = ser.readline().decode('utf-8').strip()
                try:
                    if "Capacitance:" in data and "nF" in data:
                        capacitance = float(data.split("Capacitance: ")[1].split(" nF")[0])
                        predicted_label = knn.predict([[capacitance]])[0]

                        # Store values for visualization
                        data_points.append(capacitance)
                        labels_list.append(predicted_label)

                        # Update plot
                        ax.clear()
                        ax.scatter(range(len(data_points)), data_points, c=['g' if lbl == "100nF" else 'r' for lbl in labels_list], label="Capacitance Values")
                        ax.axhline(y=100, color='b', linestyle='--', label="100nF Reference")
                        ax.set_xlabel("Reading Count")
                        ax.set_ylabel("Capacitance (nF)")
                        ax.set_title("Real-time Capacitance Classification")
                        ax.legend()
                        plt.pause(0.1)

                    else:
                        print(f"Skipping invalid data: {data}")

                except (IndexError, ValueError):
                    print(f"Error parsing data: {data}")

            # Update progress bar
            elapsed_time = time.time() - start_time
            pbar.update(min(elapsed_time - pbar.n, 1))

finally:
    print("End of prediction")
    ser.close()  # Ensure serial closes properly
    plt.ioff()  # Disable interactive mode
    plt.show()  # Display final plot
