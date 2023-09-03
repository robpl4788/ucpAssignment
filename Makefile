CC = gcc
CFLAGS = -Wall -pedantic -ansi
OBJ = main.o random.o printBoard.o
EXEC = traffic

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o: main.c main.h random.h printBoard.h constants.h
	$(CC) -c main.c $(CFLAGS)

random.o: random.c random.h
	$(CC) -c random.c $(CFLAGS)


printBoard.o: printBoard.c printBoard.h constants.h
	$(CC) -c printBoard.c $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJ)