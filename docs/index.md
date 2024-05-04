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
