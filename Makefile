test: build-test build-sqlite3 build-database build-date build-goal build-terminal build-user build-workout
	g++ -o test ./obj/test.o ./obj/sqlite3.o ./obj/database.o ./obj/date.o ./obj/goal.o ./obj/terminal.o ./obj/user.o ./obj/workout.o
	mv ./test ./bin/

build: build-main build-sqlite3 build-database build-date build-goal build-terminal build-user build-workout
	g++ -o main ./obj/main.o ./obj/sqlite3.o ./obj/database.o ./obj/date.o ./obj/goal.o ./obj/terminal.o ./obj/user.o ./obj/workout.o
	mv ./main ./bin/

build-test:
	mkdir bin obj
	g++ -c ./tests/test.cpp
	mv ./test.o ./obj/

build-main:
	mkdir bin obj
	g++ -c ./src/main.cpp
	mv ./main.o ./obj/

build-sqlite3:
	gcc -c ./src/sqlite3.c
	mv ./sqlite3.o ./obj/

build-database:
	g++ -c ./src/database.cpp
	mv ./database.o ./obj/

build-date:
	g++ -c ./src/date.cpp
	mv ./date.o ./obj/

build-goal:
	g++ -c ./src/goal.cpp
	mv ./goal.o ./obj/

build-terminal:
	g++ -c ./src/terminal.cpp
	mv ./terminal.o ./obj/

build-user:
	g++ -c ./src/user.cpp
	mv ./user.o ./obj/

build-workout:
	g++ -c ./src/workout.cpp
	mv ./workout.o ./obj/

clean:
	rm -f ./bin/main
	rm -f ./bin/*.db*
	rm -f ./obj/*.o

run: build
	./bin/main
	mv ./Application.db ./bin
	if [ ! -f ./Application.db-journal ]; then mv ./Application.db-journal ./bin
	fi

check:
shell: /usr/bin/bash -e {0}

distcheck:
shell: /usr/bin/bash -e {0}
