#include "../include/goal.h"

Goal::Goal(int id, const std::string& goal) : id(id), goal(goal) {}
Goal::Goal(){}

int Goal::getId() const {
    return id;
}

void Goal::setId(int id) {
    this->id = id;
}

const std::string& Goal::getGoal() const {
    return goal;
}

void Goal::setGoal(const std::string& goal) {
    this->goal = goal;
}