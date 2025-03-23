import serial
import serial.tools.list_ports
import time
from tqdm import tqdm
import numpy as np
import matplotlib.pyplot as plt

# Determine COM port for PSoC connection
desired_name = "KitProg"  # Replace with the part of the port description you're looking for
comPort = ''
baud = 57600

ports = serial.tools.list_ports.comports()
for port in ports:
    # Check if the desired name is in the description
    if desired_name.lower() in port.description.lower():
        comPort = port.device
        # print("Found port:", port.device)

# Serial connection setup 
ser = serial.Serial(comPort, baud, timeout=1)

start_time = time.time()
duration = 300  # Collect data for 5 minutes (adjust as needed)

capacitances = []

# Set up the real-time plot
plt.ion()  # Turn on interactive mode
fig, ax = plt.subplots()
line, = ax.plot([], [], 'b-', label="Capacitance")
ax.set_xlabel('Sample Number')
ax.set_ylabel('Capacitance (nF)')
ax.set_title('Real-time Capacitance Data')
ax.legend()

# Data collection loop with progress bar
with tqdm(total=duration, desc="Collecting Data", bar_format="{l_bar}{bar} {n_fmt}/{total_fmt}s") as pbar:
    while time.time() - start_time < duration:
        if ser.in_waiting > 0:
            data = ser.readline().decode('utf-8').strip()
            try:
                if "Capacitance:" in data and "nF" in data:
                    capacitance = float(data.split("Capacitance: ")[1].split(" nF")[0])
                    capacitances.append(capacitance)

                    # Update the plot with new data
                    x_data = np.arange(len(capacitances))
                    line.set_data(x_data, capacitances)
                    ax.relim()                # Recalculate limits
                    ax.autoscale_view()       # Rescale the view to show new data
                    plt.draw()                # Update the figure
                    plt.pause(0.001)          # Brief pause to allow the GUI to process events
                else:
                    print(f"Skipping invalid data: {data}")
            except (IndexError, ValueError):
                print(f"Error parsing data: {data}")

        # Update progress bar
        elapsed_time = time.time() - start_time
        pbar.update(min(elapsed_time - pbar.n, 1))

ser.close()  # Close the serial connection after data collection
plt.ioff()   # Turn interactive mode off
plt.show()   # Keep the plot window open after the loop ends
