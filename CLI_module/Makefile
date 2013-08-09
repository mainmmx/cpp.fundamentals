all: server.exe client.exe



server.exe: server.o CServer.o CModule.o
	g++ server.o CServer.o CModule.o -o server.exe

server.o: server.cpp GlobalConstants.h
	g++ -c -g server.cpp

CServer.o: CServer.cpp CServer.h GlobalConstants.h CModule.h
	g++ -c -g CServer.cpp

CModule.o: CModule.cpp CModule.h GlobalConstants.h
	g++ -c -g CModule.cpp



client.exe: client.o CClient.o
	g++ client.o CClient.o -o client.exe

client.o: client.cpp GlobalConstants.h
	g++ -c -g client.cpp

CClient.o: CClient.cpp CClient.h GlobalConstants.h
	g++ -c -g CClient.cpp



clean:
	rm -rf *.o *.exe
