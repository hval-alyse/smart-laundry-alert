# Smart Laundry Drying Assistant

An IoT-based environmental monitoring system designed to evaluate suitable outdoor laundry drying conditions using wireless Arduino sensor nodes and a Python coordination system.

Developed as part of postgraduate networking coursework, the project explores wireless communication, embedded systems, environmental sensing, and distributed IoT architecture using Arduino, XBee modules, and Raspberry Pi/Linux systems.

<p align="center">
  <img src="docs/Smart Laundry Diagram.png" width="700">
  </br>
  <sub>
    <a href="code/Sensor.ino"><code>Sensor</code></a> Environmental sensing →
    <a href="code/Coordinator.py"><code>Coordinator</code></a> Data processing →
    <a href="code/Receiver.ino"><code>Receiver</code></a> Output
  </sub>
</p>

## Features

- Wireless environmental monitoring using XBee communication
- Temperature, humidity, and ambient light sensing
- Python-based coordination and condition evaluation
- Arduino receiver feedback system with visual alerts
- Distributed IoT architecture using multiple devices

The following enhancements were considered but not implemented due to scope and time constraints, or suggested post-mortem as potential improvements:

- Integrate with weather forecasts - to verify measurements in real time and predict optimal conditions
- Mobile or web dashboard for real-time monitoring
- Notification system (e.g., SMS or push alerts when conditions change)

---

## System Components

### Sensor Node
- **Composition:** DHT11 temperature/humidity sensor, photoresistor (light sensor), Arduino Uno, XBee module  
- **Purpose:** Collects environmental data and transmits formatted readings wirelessly to the receiver node

### Receiver Node
- **Composition:** Arduino Uno, XBee module, LED output circuit  
- **Purpose:** Receives wireless sensor data and provides local visual feedback based on coordinator decisions

### Coordinator
- **Composition:** Python script running on Raspberry Pi / Linux system, also connected with XBee modules
- **Purpose:** Processes incoming sensor data, evaluates environmental thresholds, and determines suitability for drying conditions

---

## Repository Structure

| File | Purpose |
|---|---|
| <a href="code/Sensor.ino">`Sensor.ino`</a> | Reads environmental sensor data and transmits readings wirelessly |
| <a href="code/Receiver.ino">`Receiver.ino`</a> | Receives XBee data and controls LED feedback behaviour |
| <a href="code/Coordinator.py">`Coordinator.py`</a> | Processes incoming data and evaluates drying conditions |

---

## Drying Condition Logic

With the assumption that clothes is optimally air-dried in sunny and dry environment, the coordinator evaluates environmental conditions using simple thresholds:

- Temperature ≥ 18°C  
- Humidity ≤ 60%  
- Light level ≥ 15  

If all three conditions are met, the system indicates suitable drying conditions; otherwise, it signals that conditions are not ideal and to take the clothes indoors. This can be due to nighttime or rainstorms.

This logic is intentionally implemented as a simplified placeholder due to the absence of integration with external weather forecast APIs, which were considered for future enhancement but not included within the project scope and timeframe.

---

## Notes

This repository is a reconstructed portfolio version of an academic coursework project completed during my time pursuing a Master of Information Technology. Not all original documentation and deployment materials are available.
