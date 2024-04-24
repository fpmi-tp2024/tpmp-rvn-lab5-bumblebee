#ifndef TERMINAL_H
#define TERMINAL_H

#include "date.h"
#include "user.h"
#include "workout.h"
#include "database.h"
#include <string>

class Terminal {
    private:
    User user;
    Database database;
    public:
    Terminal();
    void start();
    void showWorkouts();
    void showGoals();
    void editProfile();
    void editWorkout(Workout workout);
    void addWorkout() ;
    void addGoal();
    void editGoal(Goal goal);
    void editConfiguration();
    void actionsWorkout(Workout workout);
    void actionsGoal(Goal goal);
};

#endif  // TERMINAL_H