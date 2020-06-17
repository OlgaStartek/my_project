SHELL = /bin/sh
#to nam okreœla pow³okê 
.SUFFIXES:
# ta linijka zeruje listê sufiksów któr¹ mo¿e obs³ugiwaæ
.SUFFIXES: .cpp .h .o
#tu wpisujemy wszystkie sufiksy których bêdziemy u¿ywaæ w programach

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