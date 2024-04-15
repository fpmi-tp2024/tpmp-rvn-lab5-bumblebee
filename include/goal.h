#ifndef GOAL_H
#define GOAL_H

#include <string>

class Goal {
private:
    int id;
    std::string goal;

public:
    Goal();
    Goal(int id, const std::string& goal);

    int getId() const;
    void setId(int id);

    const std::string& getGoal() const;
    void setGoal(const std::string& goal);
};

#endif  // GOAL_H