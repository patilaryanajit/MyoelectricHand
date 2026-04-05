# UGA Bulldog Biomechanics Club
# Electromyography Data Logging Program
# Records 1 second of EMG data from EMG Sensor and plots it, saves it to a CSV file too !!!
# Ensure that this file is saved in a dedicated folder so it can save CSV files in it

# Author - Aryan Patil
# Last Updated - April 4 2026

# Update Log 
# No updates yet, phew :)

import serial
import matplotlib.pyplot as plt
import csv
from datetime import datetime
import time

# Change this to your Arduino port, should show you which port it's on in the arduino IDE (bottom right)
port = 'COM4'

ser = serial.Serial(port, 500000, timeout=1)

time.sleep(2)
ser.reset_input_buffer()

readings = []

# Collect 1000 readings
while len(readings) < 1000:
    line = ser.readline().decode('utf-8', errors='ignore').strip()

    if "Voltage:" in line:
        try:
            value = float(line.split("Voltage:")[1])
            readings.append(value)           
        except:
            pass  # ignore malformed lines

ser.close()

# File creation
timestamp = datetime.now().strftime("%Y-%m-%d_%H-%M-%S")
filename = f"arduino_readings_{timestamp}.csv"

# Save to CSV
with open(filename, mode='w', newline='') as file:
    writer = csv.writer(file)
    writer.writerow(["Sample", "Voltage (V)"])

    for i, value in enumerate(readings):
        writer.writerow([i, value])

print(f"Data saved to {filename}")


plt.style.use('dark_background')
plt.figure()

plt.plot(readings, color='orange', linewidth=2)              

plt.xlabel("Sample Number", fontsize=12)
plt.ylabel("Voltage (V)", fontsize=12)

# Please change title to match your experiment!
plt.title("1000-Sample Electromyography Baseline Response (0V-5V), 1 kHz, Muscle Group, Month Day Year, Your Name Here!", fontsize=14)

plt.ylim(0, 5)
plt.grid(True, linestyle='--', linewidth=0.5, alpha=0.6)

for spine in plt.gca().spines.values():
    spine.set_visible(False)

plt.tight_layout()
plt.show()