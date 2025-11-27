# DHT22 Monitoring with ESP32 and ThingSpeak

This project demonstrates how to monitor **temperature and humidity** using a **DHT22 sensor** connected to an **ESP32** and send the data to **ThingSpeak** for real-time visualization. The project is fully compatible with the **Wokwi simulator**.

---

## Table of Contents

* [Components](#components)
* [Setup](#setup)
* [Wiring](#wiring)
* [Code Overview](#code-overview)
* [ThingSpeak Configuration](#thingspeak-configuration)
* [Usage](#usage)
* [Dashboard Screenshot](#dashboard-screenshot)
* [Notes](#notes)

---

## Components

* ESP32 Dev Board
* DHT22 Sensor
* Wires
* Computer with internet access
* ThingSpeak account

---

## Setup

1. Open [Wokwi](https://wokwi.com/) and create a new ESP32 project.
2. Add a **DHT22** sensor to the simulation.
3. Connect the sensor according to the wiring instructions below.
4. Copy the Arduino code into the sketch.
5. Enter your **WiFi credentials** and **ThingSpeak Write API Key**.

---

## Wiring

For ESP32:

| DHT22 Pin | ESP32 Pin |
| --------- | --------- |
| VCC       | 3.3V      |
| GND       | GND       |
| DATA      | GPIO 23   |

> In Wokwi, you can set the **Temperature** and **Humidity** values manually for simulation.

---

## Code Overview

* **WiFi connection**: Connects ESP32 to network using `WiFi.h`.
* **DHT22 sensor**: Reads temperature and humidity using `DHTesp`.
* **ThingSpeak upload**: Sends data via HTTP GET using `HTTPClient`.
* **Data interval**: Updates every **20 seconds** (ThingSpeak requires ≥15s).

**Key Libraries**:

* `WiFi.h` – network connectivity
* `DHTesp.h` – DHT22 sensor readings
* `HTTPClient.h` – HTTP requests
* `ArduinoJson.h` – optional, for JSON formatting

---

## ThingSpeak Configuration

1. Sign up at [ThingSpeak](https://thingspeak.com/).
2. Create a **New Channel**.
3. Add **Field1** (Temperature) and **Field2** (Humidity).
4. Copy the **Write API Key** and insert it in the code.
5. Publish data and view **real-time graphs**.

---

## Usage

1. Upload the sketch to the ESP32 (or run in Wokwi simulation).
2. Open the **Serial Monitor** to see readings:

   ```
   Temperature: 25.0
   Humidity: 50.0
   Data sent to ThingSpeak successfully!
   ```
3. Check your ThingSpeak channel for **live graphs** of temperature and humidity.

---

## Dashboard Screenshot
<img width="1282" height="438" alt="image" src="https://github.com/user-attachments/assets/7b4198e8-83b4-4af3-92cb-e79d967cfaf1" />

---

## Notes

* Ensure your DHT22 is correctly powered (3.3V or 5V) and connected to GPIO 23.
* Wokwi simulation allows manual adjustment of DHT22 sensor values for testing.
* ThingSpeak requires a minimum **15-second interval** between data updates.
* If the code prints `Failed to read from DHT sensor!`, check the sensor type and wiring.

---

