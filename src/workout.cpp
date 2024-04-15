#include "../include/workout.h"

Workout::Workout(int id, int duration, WorkoutType type, const Date& date)
    : id(id), duration(duration), type(type), date(date) {}

Workout::Workout(){
    
}

double Workout::calculateCalories() const {
    double calories = 0.0;
    
    //calorie calculation

    return calories;
}

int Workout::getDuration() const {
    return duration;
}

WorkoutType Workout::getType() const {
    return type;
}

const Date& Workout::getDate() const {
    return date;
}

bool Workout::setDuration(int newDuration) {
    if (newDuration <= 0) {
        return false;
    }

    duration = newDuration;
    return true;
}

bool Workout::setType(WorkoutType newType) {

    type = newType;
    return true;
}

bool Workout::setDate(const Date& newDate) {

    date = newDate;
    return true;
}

bool Workout::validate() const {

    return duration > 0 && date.validate();
}

int Workout::getId(){
    return id;
}

void Workout::printInfo() const {
    std::cout << "Workout ID: " << id << std::endl;
    std::cout << "Duration: " << duration << " minutes" << std::endl;
    std::cout << "Type: ";
    switch (type) {
        case WorkoutType::CARDIO:
            std::cout << "Cardio";
           break;
        case WorkoutType::HIIT:
            std::cout << "HIIT";
            break;
        case WorkoutType::UPPER:
            std::cout << "Upper body";
            break;
        case WorkoutType::CHEST:
            std::cout << "Chest";
            break;
        case WorkoutType::BACK:
            std::cout << "Back";
            break;
        case WorkoutType::ARMS:
            std::cout << "Arms";
            break;
        case WorkoutType::LOWER:
            std::cout << "Lower body";
            break;
        case WorkoutType::GLUTES:
            std::cout << "Glutes";
            break;
        case WorkoutType::LEGS:
            std::cout << "Legs";
            break;
        case WorkoutType::CORE:
            std::cout << "Core";
            break;
        case WorkoutType::ABS:
            std::cout << "Abs";
            break;
        case WorkoutType::RUNNING:
            std::cout << "Running";
            break;
        case WorkoutType::CYCLING:
            std::cout << "Cycling";
            break;
        case WorkoutType::SWIMMING:
            std::cout << "Swimming";
            break;
        case WorkoutType::YOGA:
            std::cout << "Yoga";
            break;
        case WorkoutType::PILATES:
            std::cout << "Pilates";
            break;
    }
    std::cout << std::endl;
    date.printInfo();
}