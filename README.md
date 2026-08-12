# ⚡ Smart Electricity Energy Meter

An IoT-based smart electricity monitoring system developed using **ESP32**, **EmonLib**, **Arduino IDE**, and **Blynk IoT** to measure and monitor electrical parameters in real time. The system measures **voltage, current, power, energy consumption, and estimated electricity cost**, while also providing remote relay control through the Blynk platform.

## 📌 Project Overview

The **Smart Electricity Energy Meter** is an IoT-enabled energy monitoring and control system designed to provide real-time information about electricity consumption.

The system uses an **ESP32** to acquire voltage and current measurements, calculate electrical parameters, display values on an LCD, and transmit the data to the **Blynk IoT dashboard** over Wi-Fi.

A relay is also integrated into the system to allow remote control of the connected load through the Blynk application.

The project demonstrates practical implementation of:

* Embedded systems
* IoT-based monitoring
* Sensor interfacing
* Real-time data processing
* Hardware-software integration
* Electrical parameter measurement
* Remote load control
* Calibration and testing

---

## 🎯 Objectives

* Measure electrical parameters in real time.
* Monitor voltage and current.
* Calculate RMS voltage and RMS current.
* Calculate power consumption.
* Track accumulated energy consumption in kWh.
* Estimate electricity cost based on energy usage.
* Display electrical parameters on an LCD.
* Send real-time data to the Blynk IoT platform.
* Control a connected relay remotely through Blynk.
* Develop a practical IoT-based energy monitoring prototype.

---

## ✨ Features

* ⚡ Real-time voltage monitoring
* 🔌 Real-time current monitoring
* 💡 Power consumption calculation
* 📊 Energy consumption tracking
* 💰 Estimated electricity cost calculation
* 📱 Remote monitoring using Blynk IoT
* 🔄 Real-time data updates
* 🖥️ LCD-based local monitoring
* 🔗 ESP32 Wi-Fi connectivity
* 🎛️ Remote relay ON/OFF control
* 🛠️ Sensor calibration and testing
* 🔧 Hardware-software integration

---

## 🧰 Technologies Used

| Technology         | Purpose                                                      |
| ------------------ | ------------------------------------------------------------ |
| **ESP32**          | Main microcontroller, data processing and Wi-Fi connectivity |
| **Arduino IDE**    | Firmware development and programming                         |
| **C/C++**          | Embedded system programming                                  |
| **EmonLib**        | Voltage, current and energy measurement                      |
| **Blynk IoT**      | Remote monitoring and relay control                          |
| **LCD**            | Local display of measured parameters                         |
| **Voltage Sensor** | Voltage measurement                                          |
| **Current Sensor** | Current measurement                                          |
| **Relay Module**   | Remote load control                                          |

---

## 🔧 Hardware Components

* ESP32 Development Board
* Voltage Measurement Sensor/Circuit
* Current Sensor
* LCD Display
* Relay Module
* AC Load
* Connecting Wires
* Breadboard / Prototype Setup
* Power Supply

---

## 🏗️ System Workflow

The complete system operates through the following workflow:

```text
                         ┌───────────────┐
                         │     START     │
                         └───────┬───────┘
                                 │
                                 ▼
                    ┌────────────────────────┐
                    │ Initialize ESP32, LCD  │
                    │       and Blynk        │
                    └────────────┬───────────┘
                                 │
                                 ▼
                    ┌────────────────────────┐
                    │ Read Voltage & Current │
                    │       Sensors          │
                    │        (calcVI)        │
                    └────────────┬───────────┘
                                 │
                                 ▼
                    ┌────────────────────────┐
                    │ Calculate Electrical   │
                    │ Parameters              │
                    │                        │
                    │ Vrms | Irms | Power    │
                    │ Energy (kWh) | Cost    │
                    └────────────┬───────────┘
                                 │
                                 ▼
                    ┌────────────────────────┐
                    │ Display Values on LCD  │
                    └────────────┬───────────┘
                                 │
                                 ▼
                    ┌────────────────────────┐
                    │ Send Data to Blynk     │
                    │      V0, V1, V2, V3    │
                    └────────────┬───────────┘
                                 │
                                 ▼
                    ┌────────────────────────┐
                    │ Blynk Relay Command    │
                    │          V4            │
                    └────────────┬───────────┘
                                 │
                       ┌─────────┴─────────┐
                       ▼                   ▼
                ┌─────────────┐     ┌─────────────┐
                │ Turn OFF    │     │ Turn ON     │
                │   Relay     │     │ Relay       │
                └─────────────┘     │  Pin 13     │
                                    └──────┬──────┘
                                           │
                                           ▼
                              ┌─────────────────────┐
                              │ Update LastMillis   │
                              │ and Repeat Cycle    │
                              └──────────┬──────────┘
                                         │
                                         └──────► Repeat
```

---

## ⚙️ Working Principle

1. The **ESP32, LCD, and Blynk** system are initialized.
2. The voltage and current sensors acquire electrical measurements from the connected load.
3. The `calcVI()` function from **EmonLib** is used to process the electrical measurements.
4. The system calculates:

   * RMS Voltage (`Vrms`)
   * RMS Current (`Irms`)
   * Power
   * Energy consumption (`kWh`)
5. The measured values are displayed on the LCD.
6. The ESP32 sends the measured data to the **Blynk IoT platform** through Wi-Fi.
7. The Blynk dashboard provides remote visualization of the electrical parameters.
8. The relay can be controlled remotely using a Blynk virtual pin.
9. The system updates `LastMillis` to maintain the required monitoring interval.
10. The measurement and monitoring cycle continues repeatedly.

---

## 📡 Blynk IoT Integration

The Blynk IoT platform is used for remote monitoring and relay control.

### Blynk Virtual Pins

| Virtual Pin | Function             |
| ----------- | -------------------- |
| **V0**      | Voltage              |
| **V1**      | Current              |
| **V2**      | Power                |
| **V3**      | Energy / kWh         |
| **V4**      | Relay ON/OFF Control |

> The virtual-pin mapping should match the assignments in the Arduino source code.

### Relay Control

The relay is controlled through the Blynk application.

* **V4** receives the relay control command.
* The relay can be switched **ON/OFF remotely**.
* The relay output is connected to **GPIO Pin 13**.
* This allows the user to remotely control the connected electrical load.

---

## 📊 Parameters Monitored

The system monitors the following electrical parameters:

| Parameter      | Unit |
| -------------- | ---- |
| Voltage        | V    |
| Current        | A    |
| Power          | W    |
| Energy         | kWh  |
| Estimated Cost | ₹    |

---

## 🧪 Calibration & Testing

Calibration and testing were performed to improve the reliability and accuracy of the measurements.

The prototype was tested through:

* Voltage measurement comparison
* Current measurement verification
* Sensor calibration
* Power calculation testing
* Energy accumulation testing
* LCD output verification
* Blynk data transmission testing
* Relay ON/OFF testing
* Hardware and software debugging

The calibration parameters were adjusted based on comparison with reference measurements.

---

## 📱 Blynk Dashboard

The Blynk IoT platform provides a remote dashboard for monitoring the system.

The dashboard displays parameters such as:

* Voltage
* Current
* Power
* Energy
* Estimated Cost

### Blynk Dashboard

Add your actual Blynk dashboard screenshot here:

```markdown
![Blynk Dashboard](images/blynk-dashboard.png)
```

---

## 🖥️ Hardware Output

The LCD provides local real-time information from the energy monitoring system.

Add your actual project photograph here:

```markdown
![Project Prototype](images/project-prototype.jpg)
```

---

## 📁 Project Structure

```text
smart-electricity-energy-meter/
│
├── README.md
├── energy_meter.ino
│
└── images/
    ├── project-prototype.jpg
    ├── blynk-dashboard.png
    └── circuit.jpg
```

> Add only the image files and project files that are actually available in the repository.

---

## 🚀 Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/YOUR-USERNAME/smart-electricity-energy-meter.git
```

### 2. Open the Project

Open `energy_meter.ino` using **Arduino IDE**.

### 3. Install Required Libraries

Install the required libraries:

* **EmonLib**
* **Blynk**

Also install and configure the **ESP32 board package** in Arduino IDE.

### 4. Configure Wi-Fi and Blynk

Configure your Wi-Fi credentials and Blynk authentication details in the Arduino code.

**Important:** Never upload real Wi-Fi passwords, Blynk authentication tokens, or other private credentials to GitHub.

### 5. Connect the Hardware

Connect the ESP32, voltage/current measurement circuits, LCD, relay, and other components according to the actual circuit used in the project.

### 6. Upload the Firmware

1. Connect the ESP32 to the computer.
2. Open the Arduino IDE.
3. Select the appropriate ESP32 board.
4. Select the correct COM port.
5. Upload the firmware.

### 7. Monitor the System

After successful deployment:

* Monitor electrical parameters on the LCD.
* Open the Blynk dashboard.
* Verify real-time data transmission.
* Test the relay ON/OFF functionality.

---

## 🔐 Safety Notice

This project involves electrical measurements and may involve **AC mains voltage**.

Do not work with mains electricity without appropriate knowledge, supervision, isolation, safety equipment, and properly rated components.

Always disconnect the power supply before modifying or troubleshooting the electrical circuit.

---

## 🎓 Learning Outcomes

Through this project, I gained practical experience in:

* ESP32-based embedded development
* IoT communication
* Sensor interfacing
* Electrical parameter measurement
* Energy monitoring
* Hardware-software integration
* Sensor calibration
* Testing and validation
* Debugging and troubleshooting
* Real-time data processing
* Blynk IoT dashboard development
* Remote relay control

---

## 🔮 Future Improvements

Possible future enhancements include:

* Improved measurement accuracy
* Historical energy consumption graphs
* Automated energy usage reports
* Energy consumption alerts
* Mobile notifications
* Improved enclosure and PCB design
* Cloud-based historical data storage
* Multiple-load monitoring
* Advanced energy analytics
* Energy usage prediction

---

## 👨‍💻 Author

**Umarfarooq Pakali**

Electronics & Communication Engineering

**Areas of Interest:** Product Development | Embedded Systems | IoT | Automation

---

⭐ If you find this project useful, consider giving the repository a star.
