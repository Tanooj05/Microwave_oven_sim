# Microwave Oven Simulation using PIC16F877A

## About
This project is a **Microwave Oven Simulation** developed using the **PIC16F877A** microcontroller and simulated in **PICSimLab**. The simulation replicates the functionalities of a real microwave oven, supporting four different cooking modes: **Conventional, Preheat, Micro Mode, and Grill Mode**. The system takes user input, processes the selected mode, and simulates the heating process accordingly.

## Features
- **4 Cooking Modes:**
  - **Conventional Mode** - Standard heating process.
  - **Preheat Mode** - Preheats the oven before cooking.
  - **Micro Mode** - Uses microwave energy for heating.
  - **Grill Mode** - Simulates grilling operations.
- LCD display for user interface.
- Keypad for mode selection and time input.
- Timer functionality to control heating duration.
- Buzzer for alert notifications.
- LEDs for indicating operational status.

## Components Used
- **Microcontroller:** PIC16F877A
- **Simulator:** PICSimLab
- **LCD Display:** 16x4 LCD
- **Keypad:** 4x4 Matrix Keypad
- **Buzzer:** For alerts
- **LEDs:** Status indicators
- **Power Supply:** 5V DC

## Procedure
### 1. Circuit Design
- Design the circuit using **PICSimLab**.
- Connect the **16x4 LCD** to the appropriate PIC16F877A pins.
- Interface the **4x4 Keypad** for input.
- Attach **LEDs** and a **buzzer** for indications.

### 2. Firmware Development
- Write the program using **Embedded C** in MPLAB IDE.
- Configure the **LCD, Keypad, Timer, and Output Pins**.
- Implement logic for the four cooking modes.
- Add time-based heating simulation.

### 3. Simulation in PICSimLab
- Load the compiled HEX file into PICSimLab.
- Run the simulation and test the microwave functions.
- Verify keypad input, display output, and mode selection.

## Working
1. The user selects a cooking mode using the **keypad**.
2. The LCD displays the selected mode and prompts for cooking time.
3. Once the time is set, the **start button** initiates the heating process.
4. The oven simulation runs for the specified time while **LED indicators** show active status.
5. At the end of the cycle, the **buzzer alerts the user**, and the oven stops automatically.

## Future Improvements
- Implement real hardware setup with PIC16F877A.
- Add a temperature sensor for real-time monitoring.
- Integrate a **touchscreen interface** for enhanced usability.

## Conclusion
This project successfully simulates a **Microwave Oven System** using **PIC16F877A** in **PICSimLab**. It provides a practical approach to learning embedded systems and microcontroller-based simulations.

