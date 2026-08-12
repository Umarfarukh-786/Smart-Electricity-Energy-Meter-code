# ⚡ Smart Electricity Energy Meter

An IoT-based smart electricity monitoring system developed using **ESP32** to measure and monitor electrical parameters in real time. The system provides information about **voltage, current, power, energy consumption, and estimated electricity cost** through an LCD display and the **Blynk IoT platform**.

## 📌 Project Overview

The Smart Electricity Energy Meter is designed to provide real-time monitoring of electrical energy consumption. The system combines embedded hardware, electrical measurement, IoT connectivity, and a mobile dashboard to help users understand and monitor electricity usage.

The project demonstrates practical implementation of:

* Embedded systems
* IoT-based monitoring
* Sensor interfacing
* Real-time data processing
* Hardware-software integration
* Energy measurement and analysis

## 🎯 Objectives

* Measure electrical parameters in real time.
* Monitor voltage and current.
* Calculate power consumption.
* Track accumulated energy usage.
* Estimate electricity cost based on energy consumption.
* Display measurements locally using an LCD.
* Send monitoring data to the Blynk IoT platform.
* Develop a practical IoT-based energy monitoring prototype.

## ✨ Features

* ⚡ Real-time voltage monitoring
* 🔌 Real-time current monitoring
* 💡 Power consumption measurement
* 📊 Energy consumption tracking
* 💰 Estimated electricity cost calculation
* 📱 Remote monitoring using Blynk
* 🖥️ Local LCD display
* 🔄 Real-time data updates
* 🛠️ Sensor calibration and testing
* 🔗 ESP32-based IoT connectivity

## 🧰 Technologies Used

| Technology      | Purpose                                   |
| --------------- | ----------------------------------------- |
| **ESP32**       | Main microcontroller and IoT connectivity |
| **Arduino IDE** | Firmware development and programming      |
| **EmonLib**     | Electrical energy measurement             |
| **Blynk IoT**   | Remote monitoring and visualization       |
| **LCD**         | Local parameter display                   |
| **Sensors**     | Voltage and current measurement           |
| **C/C++**       | Embedded system programming               |

## 🔧 Hardware Components

* ESP32 Development Board
* Current Sensor
* Voltage Measurement Circuit/Sensor
* LCD Display
* Relay Module
* AC Load
* Connecting Wires
* Breadboard / Prototype Setup
* Power Supply

> **Note:** The exact components and sensor models can be updated according to the final hardware configuration used in the project.

## 🏗️ System Workflow

```text
          AC Supply / Load
                 │
                 ▼
        ┌──────────────────┐
        │ Voltage & Current│
        │    Measurement   │
        └────────┬─────────┘
                 │
                 ▼
        ┌──────────────────┐
        │      ESP32       │
        │ Data Processing  │
        └───────┬──────────┘
                │
        ┌───────┴────────┐
        ▼                ▼
   ┌─────────┐      ┌────────────┐
   │   LCD   │      │ Blynk IoT  │
   └─────────┘      └─────┬──────┘
                          │
                          ▼
                   Mobile Dashboard
```

## ⚙️ Working Principle

1. The voltage and current measurement circuits collect electrical parameters from the connected load.
2. The **ESP32** reads the measurement data.
3. The system processes the readings to determine electrical parameters such as power and energy consumption.
4. **EmonLib** is used for energy measurement and calculation.
5. The measured values are displayed locally on the LCD.
6. The ESP32 sends the required data to the **Blynk IoT platform** through Wi-Fi.
7. The Blynk dashboard allows the user to remotely monitor the electrical parameters.
8. Energy consumption is accumulated over time and used to estimate the electricity cost.

## 📊 Parameters Monitored

The system monitors:

* **Voltage (V)**
* **Current (A)**
* **Power (W)**
* **Energy (kWh)**
* **Estimated Cost**

## 🧪 Calibration & Testing

Calibration was performed to improve the accuracy of voltage and current measurements.

The prototype was tested by:

* Comparing measured electrical values with reference measurements.
* Adjusting calibration parameters where required.
* Checking real-time readings on the LCD.
* Verifying data transmission to the Blynk dashboard.
* Testing the system with an electrical load.
* Debugging hardware and software integration issues.

## 📱 Blynk Dashboard

The Blynk IoT platform is used to remotely visualize the measured parameters.

The dashboard can display values such as:

* Voltage
* Current
* Power
* Energy
* Estimated Cost

*Add screenshots of your actual Blynk dashboard here.*

```text
Example:

![Blynk Dashboard](images/blynk-dashboard.png)
```

## 🖥️ Hardware Output

The LCD provides local real-time information from the energy monitoring system.

*Add an actual photograph of your working prototype here.*

```text
![Project Prototype](images/project-prototype.jpg)
```

## 📁 Project Structure

```text
smart-electricity-energy-meter/
│
├── README.md
├── src/
│   └── energy_meter.ino
│
├── images/
│   ├── project-prototype.jpg
│   ├── blynk-dashboard.png
│   └── circuit.jpg
│
└── docs/
    └── project-documentation.pdf
```

> Update the file names and folders according to the actual files you upload to the repository.

## 🚀 Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/YOUR-USERNAME/smart-electricity-energy-meter.git
```

### 2. Open the Project

Open the `.ino` file using **Arduino IDE**.

### 3. Install Required Libraries

Install the required libraries, including:

* EmonLib
* Blynk

Also make sure the ESP32 board package is configured in Arduino IDE.

### 4. Configure Wi-Fi and Blynk

Update the required Blynk credentials and Wi-Fi configuration in the Arduino code.

**Do not upload real Blynk authentication tokens, Wi-Fi passwords, or other credentials to GitHub.**

### 5. Connect the Hardware

Connect the ESP32, measurement circuits, LCD, relay, and sensors according to your actual circuit design.

### 6. Upload the Code

Select the correct ESP32 board and COM port in Arduino IDE and upload the firmware.

### 7. Monitor the System

After successful deployment, monitor the electrical parameters through the LCD and Blynk dashboard.

## 🔐 Safety Notice

This project involves electrical measurements and may involve **AC mains voltage**.

Do not work with mains electricity unless you have the appropriate knowledge, supervision, isolation, and safety equipment. Use properly rated components and enclosures, and disconnect power before modifying the circuit.

## 🎓 Learning Outcomes

Through this project, I gained practical experience in:

* ESP32-based embedded development
* IoT communication
* Sensor interfacing
* Electrical parameter measurement
* Energy monitoring
* Hardware-software integration
* Calibration and testing
* Debugging
* Real-time data processing
* IoT dashboard development

## 🔮 Future Improvements

Possible future enhancements include:

* Improved measurement accuracy
* Historical energy consumption graphs
* Automated energy usage reports
* Mobile notifications for abnormal consumption
* Energy usage alerts
* Improved enclosure and PCB design
* Cloud-based historical data storage
* Additional load monitoring
* More advanced energy analytics

## 👨‍💻 Author

**Umarfarooq Pakali**

Electronics & Communication Engineering
Interested in **Product Development, Embedded Systems, IoT and Automation**

---

⭐ If you find this project useful, consider giving the repository a star.
