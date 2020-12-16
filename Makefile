CC=g++
CXXFLAGS=-Wall -std=c++17
LDFLAGS=-lX11 -lpthread

SRCDIR=./src/
OBJDIR=./obj/
EXEDIR=./

EXENAME=simulation
TARGET=$(EXEDIR)$(EXENAME)

SRC=$(wildcard $(SRCDIR)*.cpp)
OBJ=$(SRC:$(SRCDIR)%.cpp=$(OBJDIR)%.o)

all: $(TARGET)
	echo "Done !"

$(TARGET): $(OBJ)
	echo "Linking project ..."
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	echo "Compiling $(notdir $<) ..."
	$(CC) -o $@ -c $^ $(CXXFLAGS)

clean:
	echo "Removing .o and binay files"
	rm -f $(OBJ) $(TARGET)

.PHONY: clean

.SILENT: