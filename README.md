# 🚗 STR91x Car Game — ARM9 Embedded Project

**Microcontrollers Course Project | ARM9 (STR91x) | C | Keil uVision**

---

## 📌 Overview
This project is an embedded **car game** developed as part of a **Microcontrollers course**.  
The system runs on an **ARM9-based STR91x microcontroller** by STMicroelectronics and was developed using **C** in **Keil uVision**.

The game is displayed on an **LCD**, uses **buttons**, **LEDs**, and an **ADC input**, and demonstrates real-time embedded programming concepts.

---

## 🧠 Hardware Platform

- **Microcontroller:** ARM9 – **STR91x (STR912FAW44)**
- **Development Board:** **MCB-STR9**
- **IDE:** Keil uVision
- **Peripherals Used:**
  - LCD display
  - Push buttons
  - LEDs
  - ADC (analog input)

---

## 🎮 Game Description

- A car (`>`) moves between **two lanes** on an LCD screen.
- Obstacles (`#`, `*`) appear randomly and move toward the car.
- The player switches lanes using a **button**.
- A **collision** reduces lives.
- Game ends after **3 crashes**.
- **Score** increases when obstacles are avoided.
- **LEDs** provide visual feedback (movement + crash indication).
- Game speed is affected by **ADC input** (voltage-controlled speed).

---

## ⚙️ Main Features

- LCD graphics and cursor control
- Random obstacle generation
- Button-based user input
- ADC-based speed control
- LED animation
- Collision detection
- Score and lives tracking
- Game-over screen

---

## 🧩 Software Structure

```text
STR91x-Car-Game/
│
├── main.c              # Main game logic
├── STR91x.s            # Startup file
├── STR91xCFG.s         # MCU configuration
│
├── Intio.c             # GPIO & peripherals initialization
├── Int_a2d.c           # ADC initialization and handling
├── basica2d.c          # Basic ADC utilities
│
├── LCD.c               # LCD driver
├── LCD.h               # LCD header
├── basiclcd.c          # LCD helper functions
├── UserFont.c          # Custom LCD fonts
│
└── README.md           # Project documentation

