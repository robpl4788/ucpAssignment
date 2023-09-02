CC = gcc
CFLAGS = -Wall -pedantic -ansi
OBJ = main.o random.o
EXEC = traffic

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o: main.c main.h random.h
	$(CC) -c main.c $(CFLAGS)

random.o: random.c random.h
	$(CC) -c random.c $(CFLAGS)


clean:
	rm -f $(EXEC) $(OBJ)