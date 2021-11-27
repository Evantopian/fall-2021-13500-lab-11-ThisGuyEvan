CXXFLAGS= -std=c++11
OBJECTS = profile.o

main: main.o $(OBJECTS)
	g++ -o main main.o $(OBJECTS)


tests: tests.o $(OBJECTS)
	g++ -o tests tests.o $(OBJECTS)


main.o: main.cpp

tests.o: tests.cpp doctest.h

profile.o: profile.cpp profile.h


clean:
	rm -f *.o main tests
