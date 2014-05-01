all: bin/main

SRC=$(wildcard src/*.cc)
HEAD=$(wildcard src/*.hh)

bin/main: $(SRC) $(HEAD)
	g++ $(SRC) -o bin/main
