#include "../include/terminal.h"
#include <iostream>

using namespace std;

Terminal::Terminal(){
    user = User();
    database = Database();
}
void Terminal::start(){
    cout << "Select an action: \n";
    cout << "1. Show training sessions\n";
    cout << "2. Show goals\n";
    cout << "3. Edit profile\n";
    int action;
    cin >> action;
    switch(action){
        case 1:
            showWorkouts();
            break;

        case 2:
            showGoals();
            break;

        case 3:
            editProfile();
            break;

        default:
            cout << "Action is undefined";
            start();
            break;
    }
}

void Terminal::showWorkouts() {
    vector<Workout> data = database.getWorkouts();
    for(auto it : data)
    {
        it.printInfo();
    }
    cout << "Write 'add' to add new workout or 'back' to back to the start\n";
    cout << "Choose workout ID or add: ";
    string action;
    cin >> action;
    if(action == "add")
    {
        addWorkout();
    } else if(action == "back")
    {
        start();
    }else
        {
        bool flag = false;
        Workout w;
        for(auto it : data){
            if(it.getId() == stoi(action))
            {
                flag == true;
                w = it;
            }
        }
        if(flag){
            actionsWorkout(w);
        }
        else{
            cout << "Action is undefined";
            showWorkouts();
        }

    }
}

void Terminal::showGoals(){
    vector<Goal> data = database.getGoals();
     for(int i = 0; i < data.size(); i++)
    {
        cout << data[i].getId() << " . " << data[i].getGoal() << endl;
    }
    cout << "Write 'add' to add new goal\n";
    cout << "Choose goal ID or add: ";
    string action;
    cin >> action;
    if(action == "add")
    {
        addGoal();
    } else if(action == "back"){
        start();
    } else {
        bool flag = false;
        Goal g;
        for(auto it : data){
            if(it.getId() == stoi(action))
            {
                flag == true;
                g = it;
            }
        }
        if(flag){
            actionsGoal(g);
        }
        else{
            cout << "Action is undefined";
            showGoals();
        }

    }
}

void Terminal::editProfile(){
    std::string name;
    int age;
    double height;
    double weight;

    std::cout << "Current name: " << user.getName() << std::endl;
    std::cout << "Enter new name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Current age: " << user.getAge() << std::endl;
    std::cout << "Enter new age: ";
    std::cin >> age;

    std::cout << "Current height: " << user.getHeight() << " cm" << std::endl;
    std::cout << "Enter new height (in cm): ";
    std::cin >> height;

    std::cout << "Current weight: " << user.getWeight() << " kg" << std::endl;
    std::cout << "Enter new weight (in kg): ";
    std::cin >> weight;

    database.editProfile(User(name, age,height,weight));
    start();
}

void Terminal::editWorkout(Workout workout){
    int duration;
    int typeInt;
    int day, month, year;

    std::cout << "Current workout ID: " << workout.getId() << std::endl;
    
    std::cout << "Enter new workout duration (in minutes): ";
    std::cin >> duration;
    workout.setDuration(duration);

    std::cout << "Enter new workout type (0 - CARDIO, 1 - HIIT, 2 - UPPER, ...): ";
    std::cin >> typeInt;
    WorkoutType newType = static_cast<WorkoutType>(typeInt);
    workout.setType(newType);

    std::cout << "Enter new workout date (day month year): ";
    std::cin >> day >> month >> year;
    Date newDate(day, month, year);
    workout.setDate(newDate);
    database.editWorkout(workout);
    showWorkouts();
}

void Terminal::editGoal(Goal goal){
    std::string newGoal;

    std::cout << "Current goal ID: " << goal.getId() << std::endl;
    
    std::cout << "Enter new goal: ";
    std::cin.ignore();
    std::getline(std::cin, newGoal);
    database.editGoal(Goal(goal.getId(),newGoal));
    showGoals();
}

void Terminal::addWorkout(){
    int id, duration;
    int typeInt;
    int day, month, year;

    std::cout << "Enter workout ID: ";
    std::cin >> id;

    std::cout << "Enter workout duration (in minutes): ";
    std::cin >> duration;

    std::cout << "Enter workout type (0 - CARDIO, 1 - HIIT, 2 - UPPER, ...): ";
    std::cin >> typeInt;
    WorkoutType type = static_cast<WorkoutType>(typeInt);

    std::cout << "Enter workout date (day month year): ";
    std::cin >> day >> month >> year;
    Date date(day, month, year);

    database.addWorkout(Workout(id, duration, type, date));
    showWorkouts();
}

void Terminal::addGoal(){
    int id;
    std::string goal;

    std::cout << "Enter goal ID: ";
    std::cin >> id;

    std::cout << "Enter goal: ";
    std::cin.ignore(); 
    std::getline(std::cin, goal);
    database.addGoal(Goal(id,goal));
    showGoals();
}

void Terminal::actionsWorkout(Workout workout) {
    cout << "Select an action: \n";
    cout << "1. Edit workout \n";
    cout << "2. Delete workout \n";
    cout << "3. Go back \n";
    int action;
    cin >> action;
    switch(action){
        case 1:
            editWorkout(workout);
            break;

        case 2:
            database.deleteWorkout(workout);
            break;

        case 3:
            showWorkouts();
            break;

        default:
            cout << "Action is undefined";
            actionsWorkout(workout);
            break;
    }
}

void Terminal::actionsGoal(Goal goal){
    cout << "Select an action: \n";
    cout << "1. Edit goal \n";
    cout << "2. Delete goal \n";
    cout << "3. Go back \n";
    int action;
    cin >> action;
    switch(action){
        case 1:
            editGoal(goal);
            break;

        case 2:
            database.deleteGoal(goal);
            break;

        case 3:
            showWorkouts();
            break;

        default:
            cout << "Action is undefined";
            actionsGoal(goal);
            break;
    }
}