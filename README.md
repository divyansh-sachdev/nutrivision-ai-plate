<div align="center">

# NutriVision AI Plate

**Smart dining plate pairing overhead vision with precision weighing for nutritional breakdown**

![Domain](https://img.shields.io/badge/Domain-Edge_Vision_+_Analytics-00F3FF?style=for-the-badge) ![Platform](https://img.shields.io/badge/Platform-ESP32--CAM-9D00FF?style=for-the-badge) ![Weighing](https://img.shields.io/badge/Weighing-24--bit_HX711-0066FF?style=for-the-badge)

![ESP32](https://img.shields.io/badge/ESP32-0D1117?style=flat-square&logo=espressif&logoColor=white) ![Arduino](https://img.shields.io/badge/Arduino-0D1117?style=flat-square&logo=arduino&logoColor=white) ![C++](https://img.shields.io/badge/C++-0D1117?style=flat-square&logo=cplusplus&logoColor=white) ![ESP32--CAM](https://img.shields.io/badge/ESP32--CAM-0D1117?style=flat-square) ![HX711](https://img.shields.io/badge/HX711-0D1117?style=flat-square) ![Load_Cell](https://img.shields.io/badge/Load_Cell-0D1117?style=flat-square)

</div>

---

## Overview

A dining plate that reports what you are eating and how much of it. An overhead ESP32-CAM identifies
the food category while a load cell under the plate base measures the actual portion mass, and the two
are combined against a macronutrient table to produce calories, protein and carbohydrate figures.

Vision alone cannot estimate portion size reliably — depth and density are ambiguous from a single
overhead frame. Pairing the classifier with a real 24-bit weight measurement is what turns a food
*label* into an accurate nutritional *quantity*.

## Domain &amp; Techniques

| Layer | Implementation |
| :--- | :--- |
| **Weight Trigger** | Continuous tare with weight-delta detection so the pipeline only fires when food is actually served |
| **Portion Measurement** | 5&nbsp;kg load cell through an HX711 24-bit amplifier — gram-level resolution |
| **Visual Classification** | Overhead ESP32-CAM captures the plate and resolves a food class index |
| **Nutrition Lookup** | `lookupFood()` maps the class index into a macronutrient record (kcal, protein, carbohydrate per 100&nbsp;g) |
| **Fusion** | Measured portion mass &times; per-100&nbsp;g profile &rarr; actual calories and macros for the serving |

## Pipeline

```
Load cell --HX711--> weight delta --[ food served? ]--> trigger
                                                          |
                                                          v
                                    ESP32-CAM captures overhead frame
                                                          |
                                                          v
                                              food class index
                                                          |
                                                          v
                               lookupFood() --> kcal / protein / carbs per 100g
                                                          |
                          measured mass  x  per-100g profile
                                                          |
                                                          v
                                    serving calories + macro breakdown
```

## Hardware

- **ESP32-CAM**: Edge camera module with 4MB PSRAM.
- **HX711 ADC**: 24-bit precision load cell amplifier.
- **5kg Load Cell**: Mounted within the plate base.

## Repository Layout

| Path | Purpose |
| :--- | :--- |
| `NutriVisionPlate.ino` | Main firmware — tare/weigh loop, capture trigger, fusion output |
| `food_classifier.h` | Macronutrient database and `lookupFood()` class-index resolution |
| `config.example.h` | Calibration factor and thresholds — copy to `config.h` |

## Project Status

**Implemented:** weight-triggered capture, HX711 portion measurement, class-index &rarr; macronutrient
resolution, and mass-scaled nutritional output across a five-item food database.

**Roadmap:** the classification stage currently resolves a class index supplied to `lookupFood()`; the
on-device inference that produces that index from the camera frame is the next build step. A
quantized MobileNet exported through TFLite Micro is the intended approach — the sibling repo
[esp32cam-tinyml-object-detection](https://github.com/divyansh-sachdev/esp32cam-tinyml-object-detection)
contains the INT8 quantization and C-array export toolchain to do exactly that. Expanding the food
database beyond five entries follows from there.

---

<div align="center">
  <sub>
    Part of the <b>AI + Robotics</b> engineering portfolio of
    <a href="https://github.com/divyansh-sachdev">Divyansh Sachdev</a><br>
    90+ national &amp; international competition wins &middot; IIT / NIT / IIIT podiums
  </sub>
</div>
