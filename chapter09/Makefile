all: exercise01 exercise02 exercise03 exercise04



exercise01: exercise01.o golf.o
	g++ exercise01.o golf.o -o exercise01.exe

exercise01.o: exercise01.cpp golf.h
	g++ -c exercise01.cpp
	
golf.o: golf.cpp golf.h
	g++ -c golf.cpp



exercise02: exercise02.o
	g++ exercise02.o -o exercise02.exe

exercise02.o: exercise02.cpp
	g++ -c exercise02.cpp



exercise03: exercise03.o
	g++ exercise03.o -o exercise03.exe

exercise03.o: exercise03.cpp
	g++ -c exercise03.cpp



exercise04: exercise04.o sales.o
	g++ exercise04.o sales.o -o exercise04.exe

exercise04.o: exercise04.cpp sales.h
	g++ -c exercise04.cpp

sales.o: sales.cpp sales.h
	g++ -c sales.cpp



clean:
	rm -rf exercise*.o exercise*.exe *.o