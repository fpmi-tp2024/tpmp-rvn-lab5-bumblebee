#include "../include/user.h"

std::string User::getName() const {
    return name;
}

int User::getAge() const {
    return age;
}

double User::getHeight() const {
    return height;
}

double User::getWeight() const {
    return weight;
}

bool User::setName(const std::string& newName) {
    if (newName.empty()) {
        return false;
    }

    name = newName;
    return true;
}

bool User::setAge(int newAge) {
    if (newAge < 0) {
        return false;
    }

    age = newAge;
    return true;
}

bool User::setHeight(double newHeight) {
    if (newHeight <= 0.0) {
        return false;
    }

    height = newHeight;
    return true;
}

bool User::setWeight(double newWeight) {
    if (newWeight <= 0.0) {
        return false;
    }

    weight = newWeight;
    return true;
}

bool User::validate() const {
    return !name.empty() && age > 0 && height > 0.0 && weight > 0.0;
}

void User::printInfo() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Height: " << height << std::endl;
    std::cout << "Weight: " << weight << std::endl;
}

bool User::addWorkout() {

    return true;
}

bool User::deleteWorkout() {

    return true;
}

bool User::editWorkout() {

    return true;
}

bool User::setGoal() {

    return true;
}

void User::trackProgress(int progress) {

}

void User::viewStatistics() {

}

bool User::changeProfile(int profileId) {

    return true;
}