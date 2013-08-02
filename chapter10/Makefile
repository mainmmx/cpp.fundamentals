all: exercise01 exercise02 exercise03 exercise04 exercise05 exercise06 exercise07 exercise08


exercise01: exercise01.o BankAccount.o
	g++ exercise01.o BankAccount.o -o exercise01.exe

exercise01.o: exercise01.cpp BankAccount.h
	g++ -c exercise01.cpp

BankAccount.o: BankAccount.cpp BankAccount.h
	g++ -c BankAccount.cpp



exercise02: exercise02.o Person.o
	g++ exercise02.o Person.o -o exercise02.exe

exercise02.o: exercise02.cpp Person.h
	g++ -c exercise02.cpp

Person.o: Person.cpp Person.h
	g++ -c Person.cpp



exercise03: exercise03.o Golf.o
	g++ exercise03.o Golf.o -o exercise03.exe

exercise03.o: exercise03.cpp Golf.h
	g++ -c exercise03.cpp

Golf.o: Golf.cpp Golf.h
	g++ -c Golf.cpp



exercise04: exercise04.o Sales.o
	g++ exercise04.o Sales.o -o exercise04.exe

exercise04.o: exercise04.cpp Sales.h
	g++ -c exercise04.cpp

Sales.o: Sales.cpp Sales.h
	g++ -c Sales.cpp



exercise05: exercise05.o Stack.o
	g++ exercise05.o Stack.o -o exercise05.exe

exercise05.o: exercise05.cpp Stack.h
	g++ -c exercise05.cpp

Stack.o: Stack.cpp Stack.h
	g++ -c Stack.cpp



exercise06: exercise06.o Move.o
	g++ exercise06.o Move.o -o exercise06.exe

exercise06.o: exercise06.cpp Move.h
	g++ -c exercise06.cpp

Move.o: Move.cpp Move.h
	g++ -c Move.cpp



exercise07: exercise07.o Plorg.o
	g++ exercise07.o Plorg.o -o exercise07.exe

exercise07.o: exercise07.cpp Plorg.h
	g++ -c exercise07.cpp

Plorg.o: Plorg.cpp Plorg.h
	g++ -c Plorg.cpp



exercise08: exercise08.o List.o
	g++ exercise08.o List.o -o exercise08.exe

exercise08.o: exercise08.cpp List.h
	g++ -c exercise08.cpp

List.o: List.cpp List.h
	g++ -c List.cpp



clean:
	rm -rf exercise*.o exercise*.exe *.o