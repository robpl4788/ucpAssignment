CC = gcc
CFLAGS = -Wall -pedantic -ansi -g
OBJ = main.o random.o printBoard.o moves.o terminal.o setup.o constants.o linkedList.o
EXEC = traffic

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o: main.c main.h moves.h random.h printBoard.h constants.h terminal.h setup.h constants.h linkedList.h
	$(CC) -c main.c $(CFLAGS)

random.o: random.c random.h
	$(CC) -c random.c $(CFLAGS)

printBoard.o: printBoard.c printBoard.h constants.h
	$(CC) -c printBoard.c $(CFLAGS)

moves.o: moves.c moves.h terminal.h constants.h printBoard.h
	$(CC) -c moves.c $(CFLAGS)

terminal.o: terminal.c terminal.h
	$(CC) -c terminal.c $(CFLAGS)

setup.o: setup.c setup.h random.h constants.h
	$(CC) -c setup.c $(CFLAGS)

constants.o: constants.c constants.h
	$(CC) -c constants.c $(CFLAGS)

linkedList.o: linkedList.c linkedList.h
	$(CC) -c linkedList.c $(CFLAGS)



clean:
	rm -f $(EXEC) $(OBJ)