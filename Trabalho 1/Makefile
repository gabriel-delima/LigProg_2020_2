CC = g++
LD = g++

CFLAGS = -Wall
LFLAGS = -Wall

MAINOBJS = menu.o estadual.o nacional.o main.o 

MAIN = main

.cpp.o:
	$(CC) $(CFLAGS) -c $<

all: $(MAIN)

main: $(MAINOBJS)
	$(LD) $(LFLAGS) -o $@ $(MAINOBJS) -lm

clean:
	rm -f *.o $(MAIN)