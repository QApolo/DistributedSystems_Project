all: client2 server serverTime

DatagramPacket.o: DatagramPacket.cpp
	g++ -c DatagramPacket.cpp -Wall

DatagramSocket.o: DatagramSocket.cpp
	g++ -c DatagramSocket.cpp -Wall

Request.o: Request.cpp
	g++ -c Request.cpp -Wall

Reply.o: Reply.cpp
	g++ -c Reply.cpp -Wall

TextAnalyzer.o: TextAnalyzer.cpp
	g++ -c TextAnalyzer.cpp -Wall

client2: DatagramPacket.o DatagramSocket.o Request.o Reply.o client2.cpp
	g++ DatagramPacket.o DatagramSocket.o Request.o Reply.o client2.cpp -o client2 -lpthread

server: DatagramPacket.o DatagramSocket.o Request.o Reply.o TextAnalyzer.o server.cpp
	g++ DatagramPacket.o DatagramSocket.o Request.o Reply.o TextAnalyzer.o server.cpp -o server

serverTime: serverTime.cpp Request.o Reply.o DatagramPacket.o DatagramSocket.o
	g++ DatagramPacket.o DatagramSocket.o Request.o Reply.o serverTime.cpp -o serverTime -Wall

.PHONY: clean

clean:
	rm -rf *.o *.exe server client2 serverTime