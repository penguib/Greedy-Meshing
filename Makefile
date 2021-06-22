CC = g++
CXXFLAGS = -std=c++11 -g -Wall

SRC = $(wildcard src/*.cpp) $(wildcard src/*/*.cpp)
OBJ = $(SRC:.cpp=.o)

BIN = bin
OBJS = bin/objs
TARGET = main

all: bin link run


%.o: %.cpp 
# replace the src/ suffix with bin/objs
	$(CC) $(CXXFLAGS) -c -o $(subst src, $(OBJS), $@) $<

link: $(OBJ)
	$(CC) $(CXXFLAGS) -o $(BIN)/$(TARGET) $(subst src, $(OBJS), $(OBJ))

run:
	$(BIN)/$(TARGET)

bin:
	mkdir -p $(OBJS)

clean:
	rm -rf $(BIN)
	clear