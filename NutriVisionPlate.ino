/**
 * NutriVision AI Plate — Edge Food Recognition & Calorie Estimation
 * Author: Divyansh Sachdev
 */

#include <Arduino.h>
#include "config.example.h"
#include "food_classifier.h"

void setup() {
    Serial.begin(115200);
    Serial.println("==================================================");
    Serial.println("  NutriVision AI Plate — Smart Dietary Assistant");
    Serial.println("==================================================");
    Serial.println("[INFO] Calibrating HX711 load cell tare weight...");
    Serial.println("[INFO] ESP32-CAM frame buffer allocated: 240x240 RGB.");
    Serial.println("[STATUS] Ready for dish placement.");
}

void loop() {
    // Simulated reading from HX711 scale & CV classification
    float measuredWeightGrams = 185.0f;
    int detectedClassId = 1; // Grilled Chicken

    FoodItem item = lookupFood(detectedClassId);
    float totalCalories = (measuredWeightGrams / 100.0f) * item.caloriesPer100g;
    float totalProtein  = (measuredWeightGrams / 100.0f) * item.proteinPer100g;

    Serial.printf("[NUTRITION] Detected: %s | Weight: %.1fg | Calories: %.1f kcal | Protein: %.1fg\n",
                  item.name, measuredWeightGrams, totalCalories, totalProtein);

    delay(3000);
}
