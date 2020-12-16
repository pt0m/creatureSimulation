CC=g++

INCLUDE=./src/ ./src/behaviours/ ./src/accessories/
ODIR=./obj/
EDIR=.

CXXFLAGS=-W -std=c++17 $(INCLUDE:%=-I%)
LDFLAGS=
TARGET=simulation

HDR=$(foreach dir, $(INCLUDE), $(wildcard $(dir)*.h))
SRC=$(foreach dir, $(INCLUDE), $(wildcard $(dir)*.cpp))
OBJ=$(SRC:.cpp=.o)

all: $(TARGET)
	echo "Done !"

$(TARGET): $(OBJ) $(HDR)
	echo "Linking project ..."
	$(CC) -o $@ $(HDR) $(addprefix $(ODIR), $(notdir $(OBJ))) $(LDFLAGS)

%.o: %.cpp
	echo "Compiling $< ..."
	$(CC) -o $(ODIR)/$(notdir $@) -c $< $(CXXFLAGS)

clean:
	echo "Removing .o and binay fiels"
	rm $(ODIR)/*.o $(EDIR)/$(TARGET)

.PHONY: #clean

# .SILENT: