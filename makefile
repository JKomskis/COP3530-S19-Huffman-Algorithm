.DEFAULT_GOAL := all
CFLAGS= -Wall -pedantic -std=c++11

all: build/test run

#create build directory
build:
	mkdir -p build

#build catch main
build/catch_main.o: | build
	g++ $(CFLAGS) catch_main.cpp -c -o ./build/catch_main.o

#build huffman tree
build/huffman_tree.o: huffman_tree.cpp | build
	g++ $(CFLAGS) huffman_tree.cpp -c -o ./build/huffman_tree.o

#build tests
build/tests.o: tests.cpp huffman_tree.h | build
	g++ $(CFLAGS) tests.cpp -c -o ./build/tests.o


#build test file
build/test: build/catch_main.o build/huffman_tree.o build/tests.o | build
	g++ $(CFLAGS) build/catch_main.o build/tests.o build/huffman_tree.o -o build/test

#run test file
.PHONY: run
run: build/test
	./build/test

#delete compiled binaries
.PHONY: clean
clean:
	rm -rf build