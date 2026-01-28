
CC      = g++
CFLAGS  = -Wall -Wextra -O2 `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lGL
OUTPUT = main
SRC     = main.cpp


$(CC) $(SRC) $(CFLAGS) -o $(OUTPUT)  $(LDFLAGS)

