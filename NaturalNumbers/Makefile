all: tests.o naturalNumbers.o
	g++ -std=c++17 tests.o naturalNumbers.o

tests.o: tests.cpp naturalNumbers.h
	g++ -std=c++17 -c tests.cpp

naturalNumbers.o: naturalNumbers.cpp naturalNumbers.cpp
	g++ -std=c++17 -c naturalNumbers.cpp

clear:
	rm -rf *.o
	rm -rf ./a.out
