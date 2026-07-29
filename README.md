# IoT Smart Warehouse Monitoring System

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
