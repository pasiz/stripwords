# Compiler to use
CC=gcc

# Compiler flags
CFLAGS=-Wall -Wextra -O2

# The name of the executable
TARGET=stripwords

# Source files
SRC=stripwords.c

# Object files
OBJ=$(SRC:.c=.o)

# Default target
all: $(TARGET)

# Rule to create the executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile .c files to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	$(RM) $(OBJ) $(TARGET)

# Phony targets (targets not associated with files)
.PHONY: all clean
