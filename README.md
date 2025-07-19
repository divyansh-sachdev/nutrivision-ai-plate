# NutriVision AI Plate

A smart dining plate combining edge computer vision (ESP32-CAM) and precision weight measurement (HX711 + Load Cell) to identify food categories and calculate real-time nutritional metrics (calories, protein, carbohydrates).

## How It Works

1. **Weight Trigger**: Plate senses when food is served via continuous tare and weight delta detection.
2. **Visual Inference**: The overhead ESP32-CAM captures an image and executes a quantized MobileNet classifier.
3. **Sensor Fusion**: Multiplies calculated portion weight by known density and macronutrient profiles to output precise dietary breakdowns.

## Hardware List

- **ESP32-CAM**: Edge camera module with 4MB PSRAM.
- **HX711 ADC**: 24-bit precision load cell amplifier.
- **5kg Load Cell**: Mounted within the plate base.
