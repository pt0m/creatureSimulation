CC=g++

INCLUDE=./src/ ./src/behaviours/ ./src/accessories/
ODIR=./obj/
EDIR=.

CXXFLAGS=-W -std=c++17 $(INCLUDE:%=-I%)
LDFLAGS=
TARGET=simulation

SRC=$(foreach dir, $(INCLUDE), $(wildcard $(dir)*.cpp))
OBJ=$(SRC:.cpp=.o)

all: $(TARGET)
	echo "Done !"

$(TARGET): $(OBJ)
	$(CC) -o $@ $(addprefix $(ODIR), $(notdir $^)) $(LDFLAGS)

%.o: %.cpp
	echo "Compiling $< ..."
	$(CC) -o $(ODIR)/$(notdir $@) -c $< $(CXXFLAGS)

clean:
	echo "Removing .o and binay fiels"
	rm $(ODIR)/*.o $(EDIR)/$(TARGET)

.PHONY: #clean

.SILENT: