#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include "user.h"
#include "goal.h"
#include "workout.h"
#include "sqlite3.h"

class Database {
private:
    std::vector<Workout> workouts;
    std::vector<Goal> goals;
    sqlite3* database;

public:
    Database();
    ~Database();
    std::vector<Workout> getWorkouts();
    std::vector<Goal> getGoals();
    User getProfile();
    bool deleteWorkout(Workout workout);
    bool deleteGoal(Goal goal);
    bool addWorkout(Workout workout);
    bool addGoal(Goal goal);
    bool editWorkout(Workout workout);
    bool editGoal(Goal goal);
    bool editProfile(User user);
};

#endif  // DATABASE_H