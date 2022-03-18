CC = g++
CFLAGS = -Werror -Wall -pedantic -std=c++20

all: main

main : main.o
	$(CC) $(CFLAGS) -o main main.o
main.o : main.cpp intArr.hpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f main
	rm -f *.o
