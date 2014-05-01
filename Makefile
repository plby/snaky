all: bin/main

bin/main: src/main.cc src/position.hh
	g++ src/main.cc -o bin/main
