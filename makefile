all: IPQ

IPQ: IPQ.o
	g++ -Wall -o IPQ IPQ.o

IPQ.o: IPQ.cpp IPQ.h
	g++ -Wall -o IPQ.o -c IPQ.cpp

clean:
	rm -f IPQ  *.o