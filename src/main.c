#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/sqlite3.h"
#include "../include/callback.h"
int main(int argv, char* argv [])

    {
        sqlite3* database;
        sqlite3_stmt* parametricalQuery;
        char* errorMessage;
        char *userInput = malloc(256 * sizeof(char));
        
        char* sqlQuery_Transaction = "BEGIN TRANSACTION;";
        char* sqlQuery_Create = "CREATE TABLE IF NOT EXISTS USER (id integer PRIMARY KEY AUTOINCREMENT,"
                                "name text, age integer, height real, weight real;"
                                "CREATE TABLE IF NOT EXISTS WORKOUTS (id integer PRIMARY KEY AUTOINCREMENT, day integer, month integer, year integer, type integer,"
                                "duration integer, calories real);"
                                "CREATE TABLE IF NOT EXISTS GOALS (id integer PRIMARY KEY AUTOINCREMENT, goal text;"
                                "CREATE TABLE IF NOT EXISTS CONFIG (type integer PRIMARY KEY, coefficient_ duration real, coefficient_height real, coefficient_weight real;";
                                
        if (sqlite3_open("Tracker.db", &database) != SQLITE_OK)
        {
            sqlite3_close(database);
            return 1;
        }
        
        if (sqlite3_exec(database, sqlQuery_Create, 0, 0, &errorMessage) != SQLITE_OK)
        {
            printf("SQL error: %s\n", errorMessage);
            sqlite3_close(database);
            sqlite3_free(errorMessage);
            return 1;
        }
        
        
        char* sqlQuery_Transaction = "BEGIN TRANSACTION;";
        
        
        //добавление пользователя
        char* sqlQuery_Parametrical_User = "INSERT INTO USER (name, age, height, weight) VALUES (?, ?, ?, ?);";
        if (sqlite3_prepare_v2(database, sqlQuery_Parametrical_User, -1, &parametricalQuery, 0) == SQLITE_OK) {
            
            char *name = malloc(256 * sizeof(char));
            int age;
            double height;
            double weight;
            
            printf("Consequently input the next fields of your info: name, age, height, weight\n");
            scanf("%s%d%lf%lf", name, &age, &height, &weight);
            
            sqlite3_bind_text(parametricalQuery, 1, name, -1, SQLITE_STATIC);
            sqlite3_bind_int(parametricalQuery, 2, age);
            sqlite3_bind_double(parametricalQuery, 3, height);
            sqlite3_bind_double(parametricalQuery, 4, weight);
            
            if (sqlite3_step(parametricalQuery) == SQLITE_DONE)
            {
                printf("\nSuccess!\n\n");
            }
            
            else {
                printf("SQL error: %s\n", errorMessage);
                sqlite3_close(database);
                sqlite3_free(errorMessage);
                return 1;
            }
        }
        
        //добавление тренировки
        char* sqlQuery_Parametrical_Workouts = "INSERT INTO WORKOUTS (day, month, year, type, duration, calories) VALUES (?, ?, ?, ?, ?, ?);";
        if (sqlite3_prepare_v2(database, sqlQuery_Parametrical_Workouts, -1, &parametricalQuery, 0) == SQLITE_OK) {
            
            int day;
            int month;
            int year;
            int type;
            int duration;
            double calories;
            
            printf("Consequently input the next fields of your workout: day, month, year, type, duration, calories\n");
            scanf("%d%d%d%d%d%lf", &day, &month, &year, &type, &duration, &calories);
            
            sqlite3_bind_int(parametricalQuery, 1, day);
            sqlite3_bind_int(parametricalQuery, 2, month);
            sqlite3_bind_int(parametricalQuery, 3, year);
            sqlite3_bind_int(parametricalQuery, 4, type);
            sqlite3_bind_int(parametricalQuery, 5, duration);
            sqlite3_bind_double(parametricalQuery, 6, calories);
            
            if (sqlite3_step(parametricalQuery) == SQLITE_DONE)
            {
                printf("\nSuccess!\n\n");
            }
            
            else {
                printf("SQL error: %s\n", errorMessage);
                sqlite3_close(database);
                sqlite3_free(errorMessage);
                return 1;
            }
        }
        
        //добавление цели
        char* sqlQuery_Parametrical_Goals = "INSERT INTO GOALS (goal) VALUES (?);";
        if (sqlite3_prepare_v2(database, sqlQuery_Parametrical_Goals, -1, &parametricalQuery, 0) == SQLITE_OK) {
            
            char *goal = malloc(256 * sizeof(char));
            
            printf("Consequently input the next fields of your goals: goal\n");
            scanf("%s", goal);
            
            sqlite3_bind_text(parametricalQuery, 1, goal, -1, SQLITE_STATIC);
            
            if (sqlite3_step(parametricalQuery) == SQLITE_DONE) {
                printf("\nSuccess!\n\n");
            }
            
            else {
                printf("SQL error: %s\n", errorMessage);
                sqlite3_close(database);
                sqlite3_free(errorMessage);
                return 1;
            }
        }
        
        //получение всех тренировок
        char* sqlQuery_Select1 = "SELECT * FROM WORKOUTS;";
        if (sqlite3_exec(database, sqlQuery_Select1, __s zeqlQuery_Select, 0, &errorMessage) != SQLITE_OK)
        {
            printf("SQL error: %s\n", errorMessage);
            sqlite3_close(database);
            sqlite3_free(errorMessage);
            return 1;
        }
        
        //получение всех целей
        char* sqlQuery_Select2 = "SELECT * FROM GOALS;";
        if (sqlite3_exec(database, sqlQuery_Select2, __sqlQuery_Select, 0, &errorMessage) != SQLITE_OK)
        {
            printf("SQL error: %s\n", errorMessage);
            sqlite3_close(database);
            sqlite3_free(errorMessage);
            return 1;
        }
        
        //получение конфигурации
        char* sqlQuery_Select4 = "SELECT * FROM CONFIG;";
        if (sqlite3_exec(database, sqlQuery_Select4, __sqlQuery_Select, 0, &errorMessage) != SQLITE_OK)
        {
            printf("SQL error: %s\n", errorMessage);
            sqlite3_close(database);
            sqlite3_free(errorMessage);
            return 1;
        }
        
        //удаление цели по айди
        char* sqlQuery_Delete_Goals = "DELETE FROM GOALS WHERE id=''";
        if (sqlite3_exec(database, sqlQuery_Delete_Goals, __sqlQuery_Select, 0, &errorMessage) != SQLITE_OK)
        {
            printf("SQL error: %s\n", errorMessage);
            sqlite3_close(database);
            sqlite3_free(errorMessage);
            return 1;
        }
        
        //удаление тренировки по айди
        char* sqlQuery_Delete_Workouts = "DELETE FROM WORKOUTS WHERE id=''";
        if (sqlite3_exec(database, sqlQuery_Delete_Workouts, __sqlQuery_Select, 0, &errorMessage) != SQLITE_OK)
        {
            printf("SQL error: %s\n", errorMessage);
            sqlite3_close(database);
            sqlite3_free(errorMessage);
            return 1;
        }
        
        //получение тренировок по айди
        char* sqlQuery_Workouts = "SELECT * FROM WORKOUTS WHERE id=''";
        if (sqlite3_exec(database, sqlQuery_Workouts, __sqlQuery_Select, 0, &errorMessage) != SQLITE_OK)
        {
            printf("SQL error: %s\n", errorMessage);
            sqlite3_close(database);
            sqlite3_free(errorMessage);
            return 1;
        }
        
        //получение целей по айди
        char* sqlQuery_Goals = "SELECT * FROM GOALS WHERE id=''";
        if (sqlite3_exec(database, sqlQuery_Goals, __sqlQuery_Select, 0, &errorMessage) != SQLITE_OK)
        {
            printf("SQL error: %s\n", errorMessage);
            sqlite3_close(database);
            sqlite3_free(errorMessage);
            return 1;
        }
        
        //изменение пользователя
        char* sqlQuery_editingUser = "UPDATE USER"
                                    "SET name='', age='', height='', weight=''"
                                    "WHERE /*вот тут я хз какое условие*/"
        if (sqlite3_exec(database, sqlQuery_editingUser, __sqlQuery_Select, 0, &errorMessage) != SQLITE_OK)
        {
            printf("SQL error: %s\n", errorMessage);
            sqlite3_close(database);
            sqlite3_free(errorMessage);
            return 1;
        }
        
        
        //изменение тренировки
        char* sqlQuery_editingWorkout = "UPDATE WORKOUTS"
                                        "SET day='', month='', year='', type='', duration='', calories=''"
                                        "WHERE /*вот тут я хз какое условие*/"
        if (sqlite3_exec(database, sqlQuery_editingWorkout, __sqlQuery_Select, 0, &errorMessage) != SQLITE_OK)
        {
            printf("SQL error: %s\n", errorMessage);
            sqlite3_close(database);
            sqlite3_free(errorMessage);
            return 1;
        }
        
        //изменение цели(по айди)
        char* sqlQuery_editingGoal = "UPDATE GOALS"
                                    "SET goal=''"
                                    "WHERE id=''"
        if (sqlite3_exec(database, sqlQuery_editingWorkout, __sqlQuery_Select, 0, &errorMessage) != SQLITE_OK)
        {
            printf("SQL error: %s\n", errorMessage);
            sqlite3_close(database);
            sqlite3_free(errorMessage);
            return 1;
        }
        
        sqlite3_close(database);
        return 0;
    }
