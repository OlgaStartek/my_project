SHELL = /bin/sh
#to nam okre�la pow�ok� 
.SUFFIXES:
# ta linijka zeruje list� sufiks�w kt�r� mo�e obs�ugiwa�
.SUFFIXES: .cpp .h .o
#tu wpisujemy wszystkie sufiksy kt�rych b�dziemy u�ywa� w programach

FLAGS = -Wall -O3 -std=c++11
SFML = -lsfml-graphics -lsfml-window -lsfml-system

game.o: game.cpp game.h
	g++ -c game.cpp $(FLAGS)

main.o: SFMLGame.cpp game.h
	g++ -c SFMLGame.cpp $(FLAGS)
# to nam stworzy object files o nazwie main.o

main: main.o game.o
	g++ main.o -o $(SFML)

clean:
	rm *.o main