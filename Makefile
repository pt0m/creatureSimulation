CC=g++
CXXFLAGS=-W -std=c++17
LDFLAGS=

SRCDIR=./src/
OBJDIR=./obj/
EXEDIR=./

EXENAME=simulation
TARGET=$(EXEDIR)$(EXENAME)

HDR=$(wildcard $(SRCDIR)*.h)
SRC=$(wildcard $(SRCDIR)*.cpp)
OBJ=$(SRC:$(SRCDIR)%.cpp=$(OBJDIR)%.o)

all: $(TARGET)
	echo "Done !"

$(TARGET): $(OBJ) #$(HDR)
	echo "Linking project ..."
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	echo "Compiling $(notdir $<) ..."
	$(CC) -o $@ -c $^ $(CXXFLAGS)

clean:
	echo "Removing .o and binay fiels"
	rm -f $(OBJ) $(TARGET)

.PHONY: clean

# .SILENT: