#ifndef FOOD_CLASSIFIER_H
#define FOOD_CLASSIFIER_H

#include <Arduino.h>

struct FoodItem {
    const char* name;
    float caloriesPer100g;
    float proteinPer100g;
    float carbsPer100g;
};

const FoodItem DATABASE[] = {
    {"Steamed Rice", 130.0f, 2.7f, 28.0f},
    {"Grilled Chicken", 165.0f, 31.0f, 0.0f},
    {"Mixed Salad", 25.0f, 1.2f, 3.5f},
    {"Paneer Curry", 260.0f, 18.0f, 6.0f},
    {"Boiled Eggs", 155.0f, 13.0f, 1.1f}
};

inline FoodItem lookupFood(int classId) {
    if (classId >= 0 && classId < 5) {
        return DATABASE[classId];
    }
    return {"Unknown Food", 0.0f, 0.0f, 0.0f};
}

#endif
