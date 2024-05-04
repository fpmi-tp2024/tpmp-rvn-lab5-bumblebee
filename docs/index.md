---
title: Document Center
---

# Fitness Tracker Application

## Project Overview:
The Fitness Tracker is a command-line application designed to help users log their workouts, track their progress, and set fitness goals. The application stores workout details in a SQLite database, allowing users to view their exercise history, analyze their performance, and monitor their fitness journey.

## Functionality:
- Create new workout sessions with details such as exercise type, duration, calories burned, and date/time.
- View a summary of workout sessions, including total workouts, total duration, total calories burned, and average performance metrics.
- Set fitness goals for workout frequency, duration, and calorie burn, and track progress towards achieving them.
- Search and filter workout sessions by exercise type, date, or performance metrics.
- Edit or delete existing workout sessions to update exercise history.

## Database Schema:
The SQLite database contains a table named "workouts" with the following columns:
- workoutid (Primary Key)
- exercisetype
- duration (minutes)
- caloriesburned
- datetime

## Application Architecture:
The application is structured using functions and modules for different operations:
- Main function: Entry point for displaying menu options and handling user input.
- Workout module: Functions for adding, editing, deleting, and displaying workout sessions.
- Database module: Handles SQLite database operations like connecting, inserting, querying data, and closing connections.
- User interface module: Manages user input validation, error handling, and menu navigation.

## User Interaction:
The application features a text-based interface where users can navigate menu options using commands or numerical inputs. Users can interact to add workouts, view history, set goals, and track progress.

## Testing and Validation:
Testing is vital during development to ensure functionality, input validation, database operations, and error handling are working seamlessly. Regular testing helps identify and resolve bugs for a better user experience.

By building the Fitness Tracker application with C and SQLite, developers can enhance programming skills and gain experience in creating database-driven applications. Customize features and functionality as needed.

We have proposed a catch testing environment and a set of tests with a code coverage of 88.354167%.

# Functionality

## Use-case

This use-case diagram represents a fitness application where a user can perform various actions. The user can delete a workout, add a workout, edit a workout, set a goal, track progress, view statistics, and change their profile. These actions are all performed through the application, which interacts with a database for validation and storage of user information.

Case #1 (Interacting with the information about workouts):
1. User enters the application.
2. User selects the option to delete a workout, to add a new workout or to edit an existing workout.
3. User interacts with the workout edit feature.
4. The application saves the data to the database.
5. Finishing session.

Case #2 (Interacting with the information about goals):
1. User enters the application.
2. User selects the option to add a goal or to track a goal.
3. User interacts with the goal setting feature or the goal tracking feature
4. User views statistics regarding their workouts.
5. The application saves the data to the database.
6. Finishing session.

Case #3 (Interacting with the profile information)
1. User enters the application.
2. User selects the option to edit a profile info.
3. User interacts with the profile edit feature.
4. The application saves the data to the database.
5. Finishing session.

 ```mermaid

---
title: Case diagram
---

flowchart TD;

    User((User))-->Action_1[Delete workout]-. extends .->Action_3[Edit workout]
    User((User))-->Action_2[Add workout]-. extends .->Action_3[Edit workout]
    User((User))-->Action_3[Edit workout]-->Application((Application))
    User((User))-->Action_4[Set goal]-->Application((Application))
    User((User))-->Action_5[Track progress]-->Application((Application))
    User((User))-->Action_6[View Statistics]-->Application((Application))-->Database[(Database)]
    User((User))-->Action_7[Change profile]-->Application((Application))-->Action_8[Validate]-->Database[(Database)]

 ```

## User Sequences

 ```mermaid

---
title: Sequence diagram
---

sequenceDiagram

    User->>Application: login
    par Verification
        loop hourly
            Application->>+User: check login
            User-->>-Application: login
            alt success
                Application-->>User: continue session
            else fail
                Application-->>User: finish session
            end
        end
    and Session
        User-->>+Application: session
        par interact workout
            User-->>Application: edit a workout
            alt success
                Application-->>Database: update info
            else fail
                Application-->>User: error message
            end
        and interact goals
            User-->>Application: edit a goal
            alt success
                Application-->>Database: update info
            else fail
                Application-->>User: error message
            end
        and interact statistics
            User-->>Application: show statistics
            Application-->>User: statistics message
        and interact profile
            User-->>Application: edit a profile
            alt success
                Application-->>Database: update info
            else fail
                Application-->>User: error message
            end
        end
    end

 ```

# Specification

## Project Objects

### Date object 

Variables:
- **`day`**, represents day of the date;
- **`month`**, represents month of the date;
- **`year`**, represents year of the date.

Functions:
- **`get`** - template for each variable, returning the value of selected variable;
- **`set`** - template for each variable, taking the val``ue as an argument for selected variable, returning the status of success as a bool-type;
- **`validate()`** - function for checking the validity of current variables' values, returning the status of succes as a bool-type;
- **`printInfo()`** - function for printing the object in user-friendly form, template for print: "_DD.MM.YYYY_".

### Workout object

Variables:
- **`id`**, represents id of the workout, serves as a primary autoincrement key in database
- **`duration`**, represents duration of the workout in minutes
- **`type`**, represents type of the workout from the enumeration
- **`date`**, represents date of the workout

Functions:
- **`get`** - template for each variable, returning the value of selected variable;
- **`set`** - template for each variable, taking the value as an argument for selected variable, returning the status of success as a bool-type;
- **`calculateCalories`** - function for calculating calories depending on the duration, type and physiological parameters of user, returning the calories as a double-type;
- **`validate()`** - function for checking the validity of current variables' values, returning the status of succes as a bool-type;
- **`printInfo()`** - function for printing the object in user-friendly form, template for print: "Workout #_id_ (_date_): _type_, _duration_ mins, _calculateCalories()_ calories consumed."

### Goal object

Variables:
- **`id`**, represents id of the workout, serves as a primary autoincrement key in database
- **`goal`**, represents the sense of the goal

Functions:
- **`get`** - template for each variable, returning the value of selected variable;
- **`set`** - template for each variable, taking the value as an argument for selected variable, returning the status of success as a bool-type.

### User object

Variables:
- **`name`**, represents name of the user
- **`age`**, represents age of the user
- **`height`**, represents height of the user in inches
- **`weight`**, represents weight of the user in pounds

Functions:
- **`get`** - template for each variable, returning the value of selected variable;
- **`set`** - template for each variable, taking the value as an argument for selected variable, returning the status of success as a bool-type;
- **`validate()`** - function for checking the validity of current variables' values, returning the status of succes as a bool-type;
- **`printInfo()`** - function for printing the object in user-friendly form, template for print: "_name_, _age_ y.o., _height_/12'_height_%12'', _weight_ pds.";
- **`addWorkout()`** - function for adding the new workout to database which asks for details (type and duration) via console, returning the status of success as a bool-type;
- **`deleteWorkout()`** - function for deleting the existing workout from database which asks for details (id) via console, returning the status of success as a bool-type;
- **`editWorkout()`** - function for editing the existing workout in database which asks for details (id, type, duration) via console, returning the status of success as a bool-type;
- **`setGoal()`** - function for setting user's goals which asks for details (type, as a calorie count, duration, types of workouts) via console, returning the status of success as a bool-type;
- **`trackProgress(int)`** - function for tracking progress, taking the id-value of goal as an argument, showing the current progress of user;
- **`viewStatistics()`** - function for showing the total statistics as a total of calories consumed, types of workouts and summary of their durations;
- **`changeProfile(int)`** - function for changing the user's data, taking the type of data for change (0 - name, 1 - age, 2 - height, 3 - weight) as an argument and asking for details via console, returning the status of success as a bool-type.

### Database object

Variables:
- **`workouts`**, represents data of workouts
- **`goals`**, represents data of goals
- **`database`**, represents the object of database in sqlite3

Functions:
- **`get`** - template for each variable, returning the value of selected variable;
- **`deleteWorkout()`** - function for deleting the existing workout from database which asks for details (id) via console, returning the status of success as a bool-type;
- **`deleteGoal()`** - function for deleting the existing goal from database which asks for details (id) via console, returning the status of success as a bool-type;
- **`addWorkout()`** - function for adding the new workout to database which asks for details (type and duration) via console, returning the status of success as a bool-type;
- **`addGoal()`** - function for adding the new goal to database which asks for details (description) via console, returning the status of success as a bool-type;
- **`editWorkout()`** - function for editing the existing workout in database which asks for details (id, type, duration) via console, returning the status of success as a bool-type;
- **`editGoal()`** - function for editing the existing goal in database which asks for details (description) via console, returning the status of success as a bool-type;
- **`editProfile()`** - function for editing the profile data in database which asks for details (user's data) via console, returning the status of success as a bool-type.

### Terminal object

Variables:
- **`user`**, represents the object of the user
- **`database`**, represents the object of database in sqlite3

Functions:
- **`start()`** - initialising the process of project;
- **`showWorkouts()`** - function for showing the existing workouts from database which asks for details (id) via console, returning the status of success as a bool-type;
- **`showGoals()`** - function for showing the existing goals from database which asks for details (id) via console, returning the status of success as a bool-type;
- **`editWorkout()`** - function for editing the existing workout in database which asks for details (id, type, duration) via console, returning the status of success as a bool-type;
- **`editGoal()`** - function for editing the existing goal in database which asks for details (description) via console, returning the status of success as a bool-type;
- **`editProfile()`** - function for editing the profile data in database which asks for details (user's data) via console, returning the status of success as a bool-type.
- **`editProfile()`** - function for editing the configuration in database which asks for details (config's data) via console, returning the status of success as a bool-type.
- **`actionsWorkout()`** - function for representing the choices of varying of the workout to database which asks for details (type and duration) via console, returning the status of success as a bool-type;
- **`actionGoal()`** - function for representing the choices of varying of the goal to database which asks for details (type and duration) via console, returning the status of success as a bool-type.

 ```mermaid

classDiagram

    class WorkoutType {
        <<enumeration>>
        CARDIO
        HIIT
        UPPER
        CHEST
        BACK
        ARMS
        LOWER
        GLUTES
        LEGS
        CORE
        ABS
        RUNNING
        CYCLING
        SWIMMING
        YOGA
        PILATES
    }

    class Date {
        -day : int
        -month : int
        -year : int
        +getDay() int
        +getMonth() int
        +getYear() int 
        +setDay(int) bool
        +setMonth(int) bool
        +setYear(int) bool
        +validate() bool
        +printInfo() void
    }

    class Workout {
        -id : int
        -duration : int
        -type : WorkoutType
        -calculateCalories() double
        +getDuration() WorkoutType
        +getType() int
        +setDuration(int) bool
        +setType(WorkoutType) bool
        +validate() bool
        +printInfo() void
    }

    class User {
        -name : string
        -age : int
        -height : double
        -weight : double
        +getName() string
        +getAge() int
        +getHeight() double
        +getWeight() double
        +setName(string) bool
        +setAge(int) bool
        +setHeight(double) bool
        +setWeight(double) bool
        +validate() bool
        +printInfo() void
        +addWorkout() bool
        +deleteWorkout() bool
        +editWorkout() bool
        +setGoal() bool
        +trackProgress(int) void
        +viewStatistics() void
        +changeProfile(int) bool
    }

    class Database {
        -workouts: List~Workout~
        -goals: List~string~
    }
    
    Workout "*" --* Database
    Workout <-- "1" WorkoutType
    Workout *-- "1" Date
    User .. Database
    
 ```

## Project Components

 ```mermaid

---
title: Component diagram
---

classDiagram

    namespace Application {

        class User {
            <<component>>
        }

        class TerminalUI {
            <<component>>
        }

        class System {
            <<component>>
        }

    }
    class Database 

    User-->TerminalUI
    TerminalUI-->System
    TerminalUI-->Database
    System-->Database

 ```

 ```mermaid

---
title: File diagram
---

flowchart TD;

    File_1[main.cpp]
    File_2[user.cpp]
    File_3[workout.cpp]
    File_4[date.cpp]
    File_5[goal.cpp]
    File_6[database.cpp]
    File_7[terminal.cpp]
    File_8((SQLite3))-->File_6
    File_8((SQLite3))-->File_14
    File_9[user.h]-->File_14
    File_9[user.h]-->File_2
    File_10[workout.h]-->File_14
    File_10[workout.h]-->File_3
    File_11[date.h]-->File_14
    File_11[date.h]-->File_4
    File_12[goal.h]-->File_5
    File_13[database.h]-->File_14
    File_13[database.h]-->File_6
    File_14[terminal.h]-->File_7
    File_14[terminal.h]-->File_6
    File_14[terminal.h]-->File_1
    File_100((C++ Libraries))-->File_1
    File_100((C++ Libraries))-->File_2
    File_100((C++ Libraries))-->File_3
    File_100((C++ Libraries))-->File_4
    File_100((C++ Libraries))-->File_5
    File_100((C++ Libraries))-->File_6
    File_100((C++ Libraries))-->File_7
    File_100((C++ Libraries))-->File_14

 ```

## Project Database

### Database diagram

 ```mermaid

---
title: Database diagram
---

classDiagram

    namespace Database {
        
        class WORKOUTS {
            + id : PRIMARY AUTOINCREMENT INTEGER
            + day : INTEGER
            + month : INTEGER
            + year : INTEGER
            + type : INTEGER
            + duration : INTEGER
            + calories : REAL
        }
        
        class GOALS {
            + id : PRIMARY AUTOINCREMENT INTEGER
            + goal : TEXT
        }
        
        class CONFIG {
            + type: PRIMARY INTEGER
            + coefficient_duration : REAL
            + coefficient_height : REAL
            + coefficient_weight: REAL
        }

        class USER {
            + id : PRIMARY AUTOINCREMENT INTEGER
            + name : TEXT
            + age : INTEGER
            + height : REAL
            + weight : REAL
        }

    }
    
    WORKOUTS <|-- CONFIG
    WORKOUTS <|-- USER
    GOALS <|-- USER

 ```

### Project configuration

| type  | coefficient_duration | coefficient_height | coefficient_weight |
| ----- | -------------------- | ------------------ | ------------------ |
| 1     | 0.4                  | 1.0                | 0.8                |
| 2     | 0.5                  | 1.0                | 0.6                |
| 3     | 0.4                  | 0.9                | 0.4                |
| 4     | 0.4                  | 1.0                | 0.8                |
| 5     | 0.3                  | 1.1                | 1.2                |
| 6     | 0.8                  | 1.0                | 1.4                |
| 7     | 0.2                  | 1.2                | 1.4                |
| 8     | 0.3                  | 1.1                | 1.5                |
| 9     | 0.4                  | 1.1                | 1.4                |
| 10    | 0.4                  | 2.0                | 2.4                |
| 11    | 0.6                  | 1.8                | 3.4                |
| 12    | 1.1                  | 1.9                | 3.2                |
| 13    | 1.0                  | 1.7                | 1.0                |
| 14    | 0.3                  | 1.4                | 0.3                |
| 15    | 0.2                  | 2.0                | 0.2                |

