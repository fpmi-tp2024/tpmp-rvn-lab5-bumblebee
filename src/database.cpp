#include "../include/database.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>

Database::Database() {
sqlite3_stmt* parametricalQuery;
char* errorMessage;
const char* sqlQuery_Transaction = "BEGIN TRANSACTION;";

if (sqlite3_open("Tracker.db", &database) != SQLITE_OK) {
    printf("Не удалось открыть базу данных.\n");
    return;
}


if (sqlite3_exec(database, sqlQuery_Transaction, 0, 0, &errorMessage) != SQLITE_OK) {
    printf("SQL error: %s\n", errorMessage);
    sqlite3_free(errorMessage);
    return;
}

const char* sqlQuery_Create = "CREATE TABLE IF NOT EXISTS USER (id integer PRIMARY KEY AUTOINCREMENT, name text, age integer, height real, weight real);"
                        "CREATE TABLE IF NOT EXISTS WORKOUTS (id integer PRIMARY KEY AUTOINCREMENT, day integer, month integer, year integer, type integer, duration integer, calories real);"
                        "CREATE TABLE IF NOT EXISTS GOALS (id integer PRIMARY KEY AUTOINCREMENT, goal text);"
                        "CREATE TABLE IF NOT EXISTS CONFIG (type integer PRIMARY KEY, coefficient_duration real, coefficient_height real, coefficient_weight real);";

if (sqlite3_exec(database, sqlQuery_Create, 0, 0, &errorMessage) != SQLITE_OK) {
    printf("SQL error: %s\n", errorMessage);
    sqlite3_free(errorMessage);
    return;
}
}

Database::~Database() {

sqlite3_close(database);
}

std::vector<Workout> Database::getWorkouts() {
sqlite3_stmt* statement;
const char* sqlQuery_Select1 = "SELECT * FROM WORKOUTS;";
int result = sqlite3_prepare_v2(database, sqlQuery_Select1, strlen(sqlQuery_Select1), &statement, NULL);
if (result != SQLITE_OK) {
    const char* errorMessage = sqlite3_errmsg(database);
    printf("Error in prepare: %s\n", errorMessage);
    return std::vector<Workout>();
}

std::vector<Workout> v;
while (sqlite3_step(statement) == SQLITE_ROW) {
    int id = sqlite3_column_int(statement, 0);
    int day = sqlite3_column_int(statement, 1);
    int month = sqlite3_column_int(statement, 2);
    int year = sqlite3_column_int(statement, 3);
    int type = sqlite3_column_int(statement, 4);
    int duration = sqlite3_column_int(statement, 5);
    v.push_back(Workout(id, duration, static_cast<WorkoutType>(type), Date(day, month, year)));
    printf("Good: ");
}

sqlite3_finalize(statement);
return v;
}

std::vector<Goal> Database::getGoals() {
sqlite3_stmt* statement;
const char* sqlQuery_Select1 = "SELECT * FROM GOALS;";
int result = sqlite3_prepare_v2(database, sqlQuery_Select1, strlen(sqlQuery_Select1), &statement, NULL);
if (result != SQLITE_OK) {
    const char* errorMessage = sqlite3_errmsg(database);
    printf("Error in prepare: %s\n", errorMessage);
    return std::vector<Goal>();
}
std::vector<Goal> v;
while (sqlite3_step(statement) == SQLITE_ROW) {
    int id = sqlite3_column_int(statement, 0);
    std::string text = (char*)sqlite3_column_text(statement, 1);
    v.push_back(Goal(id,text));
}

sqlite3_finalize(statement);
return v;
}

User Database::getProfile()
{
    sqlite3_stmt* statement;
const char* sqlQuery_Select1 = "SELECT * FROM USER WHERE id=1";
int result = sqlite3_prepare_v2(database, sqlQuery_Select1, strlen(sqlQuery_Select1), &statement, NULL);
if (result != SQLITE_OK) {
    const char* errorMessage = sqlite3_errmsg(database);
    printf("Error in prepare: %s\n", errorMessage);
    return User();
}
while (sqlite3_step(statement) == SQLITE_ROW) {
    int id = sqlite3_column_int(statement, 0);
    std::string name = (char*)sqlite3_column_text(statement, 1);
    int age = sqlite3_column_int(statement,2);
    double height = sqlite3_column_double(statement,3);
    double weight = sqlite3_column_double(statement,4);
    return User(name,age,height,weight);
}

sqlite3_finalize(statement);
    return User();
}
bool Database::deleteWorkout(Workout workout) {
    std::ostringstream queryStream;
queryStream << "DELETE FROM WORKOUTS WHERE id=?";
std::string sqlQuery_Delete_Goals = queryStream.str();

sqlite3_stmt* statement;
if (sqlite3_prepare_v2(database, sqlQuery_Delete_Goals.c_str(), -1, &statement, nullptr) == SQLITE_OK)
{
    sqlite3_bind_int(statement, 1, workout.getId());

    if (sqlite3_step(statement) != SQLITE_DONE)
    {
        printf("SQL error: %s\n", sqlite3_errmsg(database));
    }
    sqlite3_exec(database, "COMMIT", 0, 0, 0);
    sqlite3_finalize(statement);
}
else
{
    printf("SQL error: %s\n", sqlite3_errmsg(database));
    return false;
}
return true;
}

bool Database::deleteGoal(Goal goal) {
std::ostringstream queryStream;
queryStream << "DELETE FROM GOALS WHERE id=?";
std::string sqlQuery_Delete_Goals = queryStream.str();

sqlite3_stmt* statement;
if (sqlite3_prepare_v2(database, sqlQuery_Delete_Goals.c_str(), -1, &statement, nullptr) == SQLITE_OK)
{
    sqlite3_bind_int(statement, 1, goal.getId());

    if (sqlite3_step(statement) != SQLITE_DONE)
    {
        printf("SQL error: %s\n", sqlite3_errmsg(database));
    }
    sqlite3_exec(database, "COMMIT", 0, 0, 0);
    sqlite3_finalize(statement);
}
else
{
    printf("SQL error: %s\n", sqlite3_errmsg(database));
    return false;
}
return true;
}

bool Database::addWorkout(Workout workout) {
 sqlite3_stmt* parametricalQuery;
 char* sqlQuery_Parametrical_Workouts = "INSERT INTO WORKOUTS (day, month, year, type, duration) VALUES (?, ?, ?, ?, ?);";
        if (sqlite3_prepare_v2(database, sqlQuery_Parametrical_Workouts, -1, &parametricalQuery, 0) == SQLITE_OK) {
            
            int day = workout.getDate().getDay();
            int month = workout.getDate().getMonth();
            int year = workout.getDate().getYear();
            int type = static_cast<int>(workout.getType());
            int duration = workout.getDuration();
            
            printf("Consequently input the next fields of your workout: day, month, year, type, duration, calories\n");
            
            sqlite3_bind_int(parametricalQuery, 1, day);
            sqlite3_bind_int(parametricalQuery, 2, month);
            sqlite3_bind_int(parametricalQuery, 3, year);
            sqlite3_bind_int(parametricalQuery, 4, type);
            sqlite3_bind_int(parametricalQuery, 5, duration);
            
            if (sqlite3_step(parametricalQuery) == SQLITE_DONE)
            {
                printf("\nSuccess!\n\n");
                sqlite3_exec(database, "COMMIT", 0, 0, 0);
            }
            
            else {
                const char* errorMessage = sqlite3_errmsg(database);
                printf("SQL error: %s\n", errorMessage);
                sqlite3_finalize(parametricalQuery);
                return false;
            }
        }   
return true;
}

bool Database::addGoal(Goal goal) {
sqlite3_stmt* parametricalQuery;
const char* sqlQuery_Parametrical_Goals = "INSERT INTO GOALS (goal) VALUES (?);";
if (sqlite3_prepare_v2(database, sqlQuery_Parametrical_Goals, -1, &parametricalQuery, 0) == SQLITE_OK) {
    char* goalText = strdup(goal.getGoal().c_str()); // Копирование строки goal.goal
    
    sqlite3_bind_text(parametricalQuery, 1, goalText, -1, SQLITE_STATIC);
    
    if (sqlite3_step(parametricalQuery) == SQLITE_DONE) {
        printf("\nSuccess!\n\n");
        free(goalText); // Освобождение выделенной памяти
        sqlite3_exec(database, "COMMIT", 0, 0, 0);
    } else {
        const char* errorMessage = sqlite3_errmsg(database); // Объявление и присвоение значения errorMessage
        printf("SQL error: %s\n", errorMessage);
        sqlite3_finalize(parametricalQuery); // Закрытие выражения
        return false;
    }
}
else{
}
return true;
}

bool Database::editWorkout(Workout workout) {
    std::ostringstream queryStream;
queryStream << "UPDATE WORKOUTS\n SET day=?, month=?, year=?, type=?, duration=?\n WHERE id=?";
std::string sqlQuery_Edit_Workout = queryStream.str();

sqlite3_stmt* statement;
if (sqlite3_prepare_v2(database, sqlQuery_Edit_Workout.c_str(), -1, &statement, nullptr) == SQLITE_OK)
{
    sqlite3_bind_int(statement, 1, workout.getDate().getDay());
    sqlite3_bind_int(statement, 2, workout.getDate().getMonth());
    sqlite3_bind_int(statement, 3, workout.getDate().getYear());
    sqlite3_bind_int(statement, 4, static_cast<int>(workout.getType()));
    sqlite3_bind_int(statement, 5, workout.getDuration());
    sqlite3_bind_int(statement, 6, workout.getId());

    if (sqlite3_step(statement) != SQLITE_DONE)
    {
        printf("SQL error: %s\n", sqlite3_errmsg(database));
    }
    sqlite3_exec(database, "COMMIT", 0, 0, 0);
    sqlite3_finalize(statement);
}
else
{
    printf("SQL error: %s\n", sqlite3_errmsg(database));
    return false;
}
return true;
}

bool Database::editGoal(Goal goal) {
    std::ostringstream queryStream;
queryStream << "UPDATE GOALS\n SET goal=?\n WHERE id=?";
std::string sqlQuery_Edit_Goal = queryStream.str();

sqlite3_stmt* statement;
if (sqlite3_prepare_v2(database, sqlQuery_Edit_Goal.c_str(), -1, &statement, nullptr) == SQLITE_OK)
{
    sqlite3_bind_text(statement, 1, goal.getGoal().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(statement, 2, goal.getId());

    if (sqlite3_step(statement) != SQLITE_DONE)
    {
        printf("SQL error: %s\n", sqlite3_errmsg(database));
    }
    sqlite3_exec(database, "COMMIT", 0, 0, 0);
    sqlite3_finalize(statement);
}
else
{
    printf("SQL error: %s\n", sqlite3_errmsg(database));
    return false;
}
return true;
}

bool Database::editProfile(User user) {
std::ostringstream queryStream;
queryStream << "UPDATE USER\n SET name=?, age=?, height=?, weight=?\n WHERE id=1";
std::string sqlQuery_Edit_User = queryStream.str();

sqlite3_stmt* statement;
if (sqlite3_prepare_v2(database, sqlQuery_Edit_User.c_str(), -1, &statement, nullptr) == SQLITE_OK)
{
    char* newUserName = strdup(user.getName().c_str());
    sqlite3_bind_text(statement, 1, newUserName, -1, SQLITE_STATIC);
    sqlite3_bind_int(statement, 2, user.getAge());
    sqlite3_bind_int(statement, 3, user.getHeight());
    sqlite3_bind_int(statement, 4, user.getWeight());

    if (sqlite3_step(statement) != SQLITE_DONE)
    {
        printf("SQL error: %s\n", sqlite3_errmsg(database));
    }
    sqlite3_exec(database, "COMMIT", 0, 0, 0);
    sqlite3_finalize(statement);
}
else
{
    printf("SQL error: %s\n", sqlite3_errmsg(database));
    return false;
}
return true;
}