CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -pedantic
OBJ = libFS.o testFS.o
TARGET = testFS

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

libFS.o: libFS.c libFS.h
	$(CC) $(CFLAGS) -c libFS.c

testFS.o: testFS.c libFS.h
	$(CC) $(CFLAGS) -c testFS.c

	# Run both programs
run: all
	./testFS

clean:
	rm -f $(OBJ) $(TARGET)
