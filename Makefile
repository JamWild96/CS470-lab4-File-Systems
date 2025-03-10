CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -pedantic
OBJ = Jam_libFS.o Jam_testFS.o
TARGET = Jam_testFS

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

Jam_libFS.o: Jam_libFS.c Jam_libFS.h
	$(CC) $(CFLAGS) -c Jam_libFS.c

Jam_testFS.o: Jam_testFS.c Jam_libFS.h
	$(CC) $(CFLAGS) -c Jam_testFS.c

	# Run both programs
run: all
	./Jam_testFS

clean:
	rm -f $(OBJ) $(TARGET)
	rm -f *.txt
