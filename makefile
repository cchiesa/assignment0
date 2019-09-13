CC = g++
CPPFLAGS = -I.
main: main.o list.o LookupTable.o
main.o: main.cpp node.h list.h LookupTable.h
list.o: list.cpp list.h
LookupTable.o: LookupTable.cpp LookupTable.h 
clean:
	rm main
	rm *.o
