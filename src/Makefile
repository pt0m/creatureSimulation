export PATH := $(PATH):./src

CC=g++
CFLAGS=-W -std=c++17
LDFLAGS=
EXEC=simulation
# SRC=main.cpp Config.cpp   \
# 	Fin.cpp Shell.cpp Ears.cpp Eyes.cpp Camouflage.cpp pp \

SRC=Aquarium.cpp Medium.cpp Creature.cpp \
	Config.cpp Factory.cpp utils.cpp \
	IBehaviour.cpp \
	Gregarious.cpp Fearful.cpp Kamikaze.cpp Farsighted.cpp Schizophrenic.cpp
OBJ=$(SRC:.cpp=.o)

all: $(EXEC)
	echo "all: $@"

$(EXEC): $(OBJ)
	echo "exec: $(OBJ)"
	#$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp %.h
	echo "$@"
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	echo "clean"
	rm -rf *.o $(EXEC)

.PHONY: clean
	echo "PHONY"

.SILENT: