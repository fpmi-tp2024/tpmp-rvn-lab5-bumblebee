build: build-main build-sqlite3 build-callback build-database build-date build-goal build-terminal build-user build-workout
	gcc -o main ./obj/main.o ./obj/sqlite3.o ./obj/callback.o ./obj/database.o ./obj/date.o ./obj/goal.o ./obj/terminal.o ./obj/user.o ./obj/workout.o
	mv ./main ./bin/

build-main:
	gcc -c ./src/main.c
	mv ./main.o ./obj/

build-sqlite3:
	gcc -c ./src/sqlite3.c
	mv ./sqlite3.o ./obj/

build-database:
	gcc -c ./src/database.c
	mv ./database.o ./obj/

build-date:
	gcc -c ./src/date.c
	mv ./date.o ./obj/

build-goal:
	gcc -c ./src/goal.c
	mv ./goal.o ./obj/

build-terminal:
	gcc -c ./src/terminal.c
	mv ./terminal.o ./obj/

build-user:
	gcc -c ./src/user.c
	mv ./user.o ./obj/

build-workout:
	gcc -c ./src/workout.c
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
