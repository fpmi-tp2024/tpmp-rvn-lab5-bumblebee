#include "../include/database.h"

std::vector<Workout> Database::getWorkouts(){
    Date date1(15, 4, 2024);
    Workout workout1(1, 30, WorkoutType::CARDIO, date1);

    Date date2(15, 4, 2024);
    Workout workout2(2, 45, WorkoutType::UPPER, date2);

    Date date3(15, 4, 2024);
    Workout workout3(3, 60, WorkoutType::YOGA, date3);
    std::vector<Workout> v;
    v.push_back(workout1);
    v.push_back(workout2);
    v.push_back(workout3);
    return v;
}

std::vector<Goal> Database::getGoals()
{
    return std::vector<Goal>();
}

bool Database::deleteWorkout(Workout workout)
{
    return false;
}

bool Database::deleteGoal(Goal goal)
{
    return false;
}

bool Database::addWorkout(Workout workout)
{
    return false;
}

bool Database::addGoal(Goal goal)
{
    return false;
}

bool Database::editWorkout(Workout workout)
{
    return false;
}

bool Database::editGoal(Goal goal)
{
    return false;
}

bool Database::editProfile(User user)
{
    return false;
}
