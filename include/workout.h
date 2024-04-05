#ifndef WORKOUT_H
#define WORKOUT_H

#include <iostream>
#include "date.h"

enum class WorkoutType {
    CARDIO,
    HIIT,
    UPPER,
    CHEST,
    BACK,
    ARMS,
    LOWER,
    GLUTES,
    LEGS,
    CORE,
    ABS,
    RUNNING,
    CYCLING,
    SWIMMING,
    YOGA,
    PILATES
};

class Workout {
private:
    int id;
    int duration;
    WorkoutType type;
    Date date;

public:
    Workout(int id, int duration, WorkoutType type, const Date& date);
    double calculateCalories() const;
    int getDuration() const;
    WorkoutType getType() const;
    const Date& getDate() const;
    bool setDuration(int newDuration);
    bool setType(WorkoutType newType);
    bool setDate(const Date& newDate);
    bool validate() const;
    void printInfo() const;
};

#endif  // WORKOUT_H