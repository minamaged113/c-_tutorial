CFLAGS=-I.
CXXFLAGS=-std=c++14 -I.
LDFLAGS=
DEPS= 
EXECUTABLE_NAME=test

all: main.o functions.o
	$(CXX) -o $(EXECUTABLE_NAME) $^ $(LDFLAGS)

main.o: main.cpp main.h

functions.o: functions.cpp functions.h

clean:
	rm -f *.o test
