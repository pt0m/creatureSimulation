main : main.cpp Aquarium.o Creature.o Medium.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Creature.o Medium.o -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

Creature.o : Creature.h Creature.cpp
	g++ -Wall -std=c++11  -c Creature.cpp -I .

Medium.o : Medium.h Medium.cpp
	g++ -Wall -std=c++11  -c Medium.cpp -I .



