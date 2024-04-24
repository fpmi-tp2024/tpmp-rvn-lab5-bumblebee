#include <iostream>
#include "../include/terminal.h"

using namespace std;

int main(){
    Terminal terminal = Terminal();
    terminal.start();
}

//cl ./src/database.cpp ./src/date.cpp  ./src/goal.cpp ./src/main.cpp ./src/terminal.cpp ./src/user.cpp ./src/workout.cpp ./src/sqlite3.c
//cl -o ./build.exe database.obj date.obj goal.obj main.obj terminal.obj user.obj workout.obj sqlite3.obj

