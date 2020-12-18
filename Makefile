CC=g++
CXXFLAGS=-Wall -std=c++17
LDFLAGS=-lX11 -lpthread

SRCDIR=./src/
OBJDIR=./obj/
EXEDIR=./
TESTDIR=./test/

EXENAME=simulation
TARGET=$(EXEDIR)$(EXENAME)
TESTNAME=test_simulations
TEST=$(TESTDIR)$(TESTNAME)

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

test: $(TEST)
	echo "Done !"

$(TEST): $(filter-out $(OBJDIR)main.o ,$(OBJ)) $(TESTDIR)*.o
	echo "Linking test ..."
	$(CC) -o $@ $^ $(LDFLAGS)

$(TESTDIR)%.o: $(TESTDIR)%.cpp
	echo "Compiling $(notdir $<) ..."
	$(CC) -o $@ -c $^ $(CXXFLAGS) -I$(SRCDIR)

clean:
	echo "Removing .o and binay files"
	rm -f $(OBJ) $(TARGET)

.PHONY: clean

.SILENT: