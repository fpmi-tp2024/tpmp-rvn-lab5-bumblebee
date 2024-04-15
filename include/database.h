#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include "workout.h"

#include <vector>
#include "user.h"
#include "goal.h"

class Database{
    private:
    std::vector<Workout> workouts;
    std::vector<Goal> goals;
    public:
    std::vector<Workout> getWorkouts();
    std::vector<Goal> getGoals();
    bool deleteWorkout(Workout workout);
    bool deleteGoal(Goal goal);
    bool addWorkout(Workout workout);
    bool addGoal(Goal goal);
    bool editWorkout(Workout workout);
    bool editGoal(Goal goal);
    bool editProfile(User user);
};

#endif  //  DATABASE_H