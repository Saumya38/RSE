CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99

# List of source files
SRC = main.c search.c filesearch.c stringsearch.c display.c

# List of object files derived from source files
OBJ = $(SRC:.c=.o)

# Output executable name
EXECUTABLE = server

# Makefile targets
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXECUTABLE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJ)
