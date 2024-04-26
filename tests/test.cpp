#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/workout.h"
#include "../include/user.h"
#include "../include/goal.h"
#include "../include/date.h"

TEST_CASE("Test Date Constructor", "[Date]") {
    Date date(1, 1, 2022);

    REQUIRE(date.getDay() == 1);
    REQUIRE(date.getMonth() == 1);
    REQUIRE(date.getYear() == 2022);
}

TEST_CASE("Test Set and Get Day", "[Date]") {
    Date date;

    bool result = date.setDay(15);
    REQUIRE(result == true);
    REQUIRE(date.getDay() == 15);

    result = date.setDay(0);
    REQUIRE(result == false);
    REQUIRE(date.getDay() == 15);

    result = date.setDay(32);
    REQUIRE(result == false);
    REQUIRE(date.getDay() == 15);
}

TEST_CASE("Test Set and Get Month", "[Date]") {
    Date date;

    bool result = date.setMonth(6);
    REQUIRE(result == true);
    REQUIRE(date.getMonth() == 6);

    result = date.setMonth(0);
    REQUIRE(result == false);
    REQUIRE(date.getMonth() == 6);

    result = date.setMonth(13);
    REQUIRE(result == false);
    REQUIRE(date.getMonth() == 6);
}

TEST_CASE("Test Set and Get Year", "[Date]") {
    Date date;

    bool result = date.setYear(2022);
    REQUIRE(result == true);
    REQUIRE(date.getYear() == 2022);

    result = date.setYear(-2022);
    REQUIRE(result == false);
    REQUIRE(date.getYear() == 2022);
}

TEST_CASE("Test Validate", "[Date]") {
    Date date(10, 5, 2023);
    REQUIRE(date.validate() == true);

    Date date2(32, 13, -2023);
    REQUIRE(date2.validate() == false);
}

TEST_CASE("Test Print Info", "[Date]") {
    Date date(15, 9, 2024);
    // Redirect cout to a stringstream for testing
    std::stringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());

    date.printInfo();

    std::string outputStr = output.str();
    // Check if the output matches the expected format
    REQUIRE(outputStr == "Date: 15/9/2024\n");

    // Restore the old cout buffer
    std::cout.rdbuf(oldCoutBuffer);
}
TEST_CASE("Test Goal Constructor", "[Goal]") {
    Goal goal(1, "Lose weight");

    REQUIRE(goal.getId() == 1);
    REQUIRE(goal.getGoal() == "Lose weight");
}

TEST_CASE("Test Set and Get Id", "[Goal]") {
    Goal goal;

    goal.setId(1);
    REQUIRE(goal.getId() == 1);

    goal.setId(2);
    REQUIRE(goal.getId() == 2);
}

TEST_CASE("Test Set and Get Goal", "[Goal]") {
    Goal goal;

    goal.setGoal("Lose weight");
    REQUIRE(goal.getGoal() == "Lose weight");

    goal.setGoal("Build muscle");
    REQUIRE(goal.getGoal() == "Build muscle");
}
TEST_CASE("Test User Constructor", "[User]") {
    User user("John", 30, 180.0, 75.0);

    REQUIRE(user.getName() == "John");
    REQUIRE(user.getAge() == 30);
    REQUIRE(user.getHeight() == Approx(180.0));
    REQUIRE(user.getWeight() == Approx(75.0));
}

TEST_CASE("Test Set and Get Name", "[User]") {
    User user;
    
    bool result = user.setName("John");
    REQUIRE(result == true);
    REQUIRE(user.getName() == "John");

    result = user.setName("");
    REQUIRE(result == false);
    REQUIRE(user.getName() == "John");
}

TEST_CASE("Test Set and Get Age", "[User]") {
    User user;

    bool result = user.setAge(30);
    REQUIRE(result == true);
    REQUIRE(user.getAge() == 30);

    result = user.setAge(-5);
    REQUIRE(result == false);
    REQUIRE(user.getAge() == 30);
}

TEST_CASE("Test Set and Get Height", "[User]") {
    User user;

    bool result = user.setHeight(180.0);
    REQUIRE(result == true);
    REQUIRE(user.getHeight() == Approx(180.0));

    result = user.setHeight(0.0);
    REQUIRE(result == false);
    REQUIRE(user.getHeight() == Approx(180.0));
}

TEST_CASE("Test Set and Get Weight", "[User]") {
    User user;

    bool result = user.setWeight(75.0);
    REQUIRE(result == true);
    REQUIRE(user.getWeight() == Approx(75.0));

    result = user.setWeight(0.0);
    REQUIRE(result == false);
    REQUIRE(user.getWeight() == Approx(75.0));
}

TEST_CASE("Test Validate2", "[User]") {
    User user("John", 30, 180.0, 75.0);
    REQUIRE(user.validate() == true);

    User user2("", 30, 180.0, 75.0);
    REQUIRE(user2.validate() == false);
}

TEST_CASE("Test Add Workout", "[User]") {
    User user("John", 30, 180.0, 75.0);
    bool result = user.addWorkout();
    REQUIRE(result == true);
    // Add additional assertions based on the expected behavior of the addWorkout() function
}

TEST_CASE("Test Delete Workout", "[User]") {
    User user("John", 30, 180.0, 75.0);
    bool result = user.deleteWorkout();
    REQUIRE(result == true);
    // Add additional assertions based on the expected behavior of the deleteWorkout() function
}

TEST_CASE("Test Edit Workout", "[User]") {
    User user("John", 30, 180.0, 75.0);
    bool result = user.editWorkout();
    REQUIRE(result == true);
    // Add additional assertions based on the expected behavior of the editWorkout() function
}

TEST_CASE("Test Set Goal", "[User]") {
    User user("John", 30, 180.0, 75.0);
    bool result = user.setGoal();
    REQUIRE(result == true);
    // Add additional assertions based on the expected behavior of the setGoal() function
}

TEST_CASE("Test Track Progress", "[User]") {
    User user("John", 30, 180.0, 75.0);
    user.trackProgress(10);
    // Add assertions to check if the progress tracking is working as expected
}

TEST_CASE("Test View Statistics", "[User]") {
    User user("John", 30, 180.0, 75.0);
    user.viewStatistics();
    // Add assertions to check if the statistics viewing is working as expected
}

TEST_CASE("Test Change Profile", "[User]") {
    User user("John", 30, 180.0, 75.0);
    bool result = user.changeProfile(1);
    REQUIRE(result == true);
    // Add additional assertions based on the expected behavior of the changeProfile() function
}
TEST_CASE("Calculate Calories", "[Workout]") {
    Date date(2022, 1, 1);
    Workout workout(1, 60, WorkoutType::CARDIO, date);
    double calories = workout.calculateCalories();
    REQUIRE(calories == Approx(0.0));
}

TEST_CASE("Set and Get Duration", "[Workout]") {
    Date date(2022, 1, 1);
    Workout workout(1, 60, WorkoutType::CARDIO, date);
    REQUIRE(workout.getDuration() == 60);

    bool result = workout.setDuration(90);
    REQUIRE(result == true);
    REQUIRE(workout.getDuration() == 90);

    result = workout.setDuration(-10);
    REQUIRE(result == false);
    REQUIRE(workout.getDuration() == 90);
}

TEST_CASE("Set and Get Type", "[Workout]") {
    Date date(2022, 1, 1);
    Workout workout(1, 60, WorkoutType::CARDIO, date);
    REQUIRE(workout.getType() == WorkoutType::CARDIO);

    bool result = workout.setType(WorkoutType::HIIT);
    REQUIRE(result == true);
    REQUIRE(workout.getType() == WorkoutType::HIIT);
}

TEST_CASE("Get Id", "[Workout]") {
    Date date(2022, 1, 1);
    Workout workout(1, 60, WorkoutType::CARDIO, date);
    REQUIRE(workout.getId() == 1);
}