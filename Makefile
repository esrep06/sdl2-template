UNAME_S:=$(shell uname -s)
CC=g++
CFLAGS=-std=c++17
INCLUDE_DIR=include
SDL2_LIB_DIR=lib/SDL2_Linux
BUILD_DIR=build
LDFLAGS= -O0 -Wall -Wextra -pedantic -lpthread -L$(SDL2_LIB_DIR) -lSDL2

SRC_DIR=src/engine

SRC+=$(shell find $(SRC_DIR) -type f -name '*.cpp')

EXECUTABLE=$(BUILD_DIR)/app

$(EXECUTABLE): src/main.cpp
	echo "Building for $(UNAME_S)..."
	$(CC) $(CFLAGS) $(SRC) $^ -o $@ -g -I$(INCLUDE_DIR) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(EXECUTABLE)

