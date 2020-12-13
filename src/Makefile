export PATH := $(PATH):./src

CC=g++
CFLAGS=-W
LDFLAGS=
EXEC=simulation
# SRC=main.cpp Config.cpp Aquarium.cpp Medium.cpp Factory.cpp Creature.cpp \
# 	Fin.cpp Shell.cpp Ears.cpp Eyes.cpp Camouflage.cpp IBehaviour.cpp \
# 	Gregarious.cpp Fearful.cpp Kamikaze.cpp Farsighted.cpp Schizophrenic.cpp
SRC=IBehaviour.cpp Gregarious.cpp Fearful.cpp Kamikaze.cpp Farsighted.cpp Schizophrenic.cpp
OBJ=$(SRC:.cpp=.o)

all: $(EXEC)
	echo "$@"

$(EXEC): $(OBJ)
	echo "$@"
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	echo "$@"
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	echo "$@"
	rm -rf *.o $(EXEC)

.PHONY: clean
	echo "$@"

.SILENT: