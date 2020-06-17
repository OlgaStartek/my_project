SHELL = /bin/sh
#to nam określa powłokę 
.SUFFIXES:
# ta linijka zeruje listę sufiksów którą może obsługiwać
.SUFFIXES: .cpp .h .o
#tu wpisujemy wszystkie sufiksy których będziemy używać w programach

FLAGS = -Wall -O3 -std=c++11
SFML = -lsfml-graphics -lsfml-window -lsfml-system

game.o: game.cpp game.h
	g++ -c game.cpp $(FLAGS)

main.o: main.cpp game.h
	g++ -c main.cpp $(FLAGS)
# to nam stworzy object files o nazwie main.o

main: main.o game.o
	g++ main.o -o $(SFML)

clean:
	rm *.o main
