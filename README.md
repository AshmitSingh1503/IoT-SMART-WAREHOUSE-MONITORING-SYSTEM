# SENTINEL: IoT Smart Warehouse Monitoring System (ESP32 + RFID)

**Best Paper Award (Track 4), NCEA-SSEM 2026**: National Student Conference on Emerging AI and Sustainable Smart Engineering & Management, organized by the IEEE Student Branches & WIE Affinity Groups, JSS University, Noida (23 September 2026)

 **[Read the paper (PDF)](paper/Smart-Warehouse-Monitoring-ESP32-RFID.pdf)** ·  **[View the certificate](paper/best-paper-certificate.jpg)**

**Authors:** Ashmit Singh, Saanvi Dheer, Harshpreet Kaur, Aditya Mishra, Akshita Gupta
Dept. of Electronics and Communication Engineering, JSS University, Noida

---

An ESP32-based IoT system designed for real-time warehouse monitoring, environmental sensing, motion detection, RFID identification, local alerts, and cloud-based data visualization.

Developed as part of a summer internship to gain practical experience in **embedded systems, sensor interfacing, IoT communication, and hardware prototyping**.

---

## Overview

Modern warehouses require continuous monitoring of environmental conditions, movement, and access to maintain efficient and secure operations.

This project demonstrates a prototype **IoT-enabled warehouse monitoring system** built around the ESP32 microcontroller. It integrates multiple sensors and peripherals to monitor environmental conditions, detect motion, identify RFID cards, generate local alerts, display system information, and transmit data to the Blynk IoT platform through Wi-Fi.

The system was implemented as a physical hardware prototype and complemented with circuit simulation for development and testing.

---

## Key Features

- Real-time temperature and humidity monitoring using DHT22
- Motion detection using a PIR sensor
- RFID card detection and identification using MFRC522
- Real-time system information displayed on an I2C LCD
- LED and buzzer-based local alerts
- Wi-Fi connectivity through ESP32
- Remote monitoring and data visualization using Blynk IoT
- Physical hardware prototype implementation
- Circuit simulation and functional testing

---

## System Architecture

The ESP32 acts as the central processing and communication unit of the system.

```text
                    ┌───────────────────┐
                    │       DHT22       │
                    │ Temperature & RH  │
                    └─────────┬─────────┘
                              │
                              ▼
┌──────────────┐       ┌─────────────┐       ┌─────────────────┐
│  PIR Sensor  │──────►│             │──────►│   I2C LCD       │
└──────────────┘       │    ESP32    │       └─────────────────┘
                       │             │
┌──────────────┐       │             │──────► LED / Buzzer
│ MFRC522 RFID │──────►│             │
└──────────────┘       └──────┬──────┘
                              │
                            Wi-Fi
                              │
                              ▼
                       ┌─────────────┐
                       │  Blynk IoT  │
                       │  Dashboard  │
                       └─────────────┘

---

## Research Paper

This project is described in the paper **"Smart Warehouse Monitoring System Integrating ESP-32 and RFID Identification"**, which won the **Best Paper Award (Track 4)** at NCEA-SSEM 2026, JSS University, Noida.

The paper covers the hardware interfacing, the polling firmware architecture, the threshold-based alert logic, the simulation-first test methodology (Wokwi, then a physical breadboard prototype), and the design limitations a production deployment would need to address.

-  [Full paper (PDF)](paper/Smart-Warehouse-Monitoring-ESP32-RFID.pdf)
-  [Best Paper Award certificate](paper/best-paper-certificate.jpg)

### Citation

```bibtex
@inproceedings{singh2026sentinel,
  title     = {Smart Warehouse Monitoring System Integrating ESP-32 and RFID Identification},
  author    = {Singh, Ashmit and Dheer, Saanvi and Kaur, Harshpreet and Mishra, Aditya and Gupta, Akshita},
  booktitle = {National Student Conference on Emerging AI and Sustainable Smart Engineering \& Management (NCEA-SSEM 2026)},
  organization = {IEEE Student Branches \& WIE Affinity Groups, JSS University},
  address   = {Noida, India},
  year      = {2026},
  note      = {Best Paper Award, Track 4}
}
```
