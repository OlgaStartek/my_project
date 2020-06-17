CC := g++
FLAGS := -Wall -std=c++11
SFML := -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio 

main.x: main.o game.o
main.o: main.cpp
game.o: game.cpp

%.x: %.o
	$(CC) $^ -o $@ $(FLAGS) -I C:/SFML/include

%.o: %.cpp %.h
	$(CC) $^ -o $@ $(SFML) -I C:/SFML/include

clean:
	rm *.o *.x
