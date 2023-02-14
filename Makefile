CFLAGS=-Wall -Wextra -std=c17 -pedantic -ggdb  `pkg-config --cflags sdl2` #additional compiler flags
LIBS=`pkg-config --libs sdl2` -lm										  #additional libraries

te: main.c 
	$(CC) $(CFLAGS) -o te main.c $(LIBS)