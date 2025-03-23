#  Automated Compensation of Environmental Changes on CO2 Gas Sensor Response
Project Supervisor: Dr. Ajay Achath Mohanan <br>
Project Members: Leong Van Jun, Vincent Law Yun Kae <br>
Project Commence Date: November 2024 - Present <br>
## Project Description <br>
The main objective of the project is to introduce Artificial Intelligence (AI) and/or machine learning (ML) tools to assist in analysing patterns in obtained carbon dioxide sensor readings and filtering of unwanted noises. <br>
This objective is achieved through proper setting up of the hardware setup and environment of the carbon dioxide sensor. Which is achieved by constructing of appropriate PCB and testing through external microcontroller units. <br>
For this project, the microcontroller unit used is the PSoC 5LP module and PCB design software used is Kicad 8.

## Changelog
### 23/3/2025:
  - Updated capacitance.py to remove KNN cluster and median filtering algorithm to display raw data output in graph
  - Added heater bang-bang control and temperature sensor (3/3 tasks)
### 3/3/2025:
  - Written Python script involving KNN machine learning algorithm to help effeciently filter outlier values in read capacitance values
### 22/2/2025:
  - Re-updated read_capacitance function
  - Included improved analogue circuitry to measure capacitance, now using an
    NE556N timer module instead of simple RC circuit (LTSpice file included!)
### 13/2/2025:
  - Completed two tasks of three: Measure capacitance via PSoC
  - Currently debugging capacitance value, current capacitance value too small!
### 12/2/2025: 
  - Uploaded PSoC Creator and Kicad project files into Github repo for the first time.
  - Completed one task of three: Interface SCD30 on PCB with PSoC 5LP to obtain CO2 concentration, temperature, and relative humidity levels (rh%)

## Reference Materials
SCD30 item website: https://sensirion.com/products/catalog/SCD30 <br>
SCD30 Datasheet: https://sensirion.com/media/documents/4EAF6AF8/61652C3C/Sensirion_CO2_Sensors_SCD30_Datasheet.pdf <br>
SCD30 Interface Description: https://sensirion.com/media/documents/D7CEEF4A/6165372F/Sensirion_CO2_Sensors_SCD30_Interface_Description.pdf <br>
SCD30 Example Code: https://github.com/Sensirion/embedded-scd/releases/tag/2.1.1 <br>

## Acknowledgement
Thank you to Dr. Ajay for his supervision and guidance for the project members throughout the project duration.
