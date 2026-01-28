CC      = g++
CFLAGS  = -Wall -Wextra -O2 `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lGL -lGLEW

OUTPUT  = main
SRC     = main.cpp

all: $(OUTPUT)

$(OUTPUT): $(SRC)
	$(CC) $(SRC) $(CFLAGS) -o $(OUTPUT) $(LDFLAGS)

clean:
	rm -f $(OUTPUT)
