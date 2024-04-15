#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

class User {
private:
    std::string name;
    int age;
    double height;
    double weight;

public:
    User();
    User(std::string name, int age, double height, double weight);
    std::string getName() const;
    int getAge() const;
    double getHeight() const;
    double getWeight() const;
    bool setName(const std::string& newName);
    bool setAge(int newAge);
    bool setHeight(double newHeight);
    bool setWeight(double newWeight);
    bool validate() const;
    void printInfo() const;
    bool addWorkout();
    bool deleteWorkout();
    bool editWorkout();
    bool setGoal();
    void trackProgress(int progress);
    void viewStatistics();
    bool changeProfile(int profileId);
};

#endif  // USER_H