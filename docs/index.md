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

Enjoy tracking your fitness journey with the Fitness Tracker application!

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

 ```mermaid

