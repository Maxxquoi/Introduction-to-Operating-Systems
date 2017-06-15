# specify the compiler
CC=gcc

# specify options for the compiler
CFLAGS=-c -Wall

all: hello

hello: main.o hello.o
    $(CC) main.o hello.o -o hello

main.o: main.cpp
    $(CC) $(CFLAGS) main.cpp

hello.o: hello.cpp
    $(CC) $(CFLAGS) hello.cpp

clean:
    rm -rf *o hello
