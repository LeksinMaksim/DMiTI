all: tests.o naturalNumbers.o COM_NN_D.o MUL_ND_N.o
	g++ -std=c++17 tests.o naturalNumbers.o COM_NN_D.o MUL_ND_N.o

tests.o: tests.cpp naturalNumbers.h COM_NN_D.h MUL_ND_N.h
	g++ -std=c++17 -c tests.cpp

MUL_ND_N.o: MUL_ND_N.cpp MUL_ND_N.h
	g++ -std=c++17 -c MUL_ND_N.cpp

COM_NN_D.o: COM_NN_D.cpp COM_NN_D.h
	g++ -std=c++17 -c COM_NN_D.cpp

naturalNumbers.o: naturalNumbers.cpp naturalNumbers.h
	g++ -std=c++17 -c naturalNumbers.cpp

clear:
	rm -rf *.o
	rm -rf ./a.out
