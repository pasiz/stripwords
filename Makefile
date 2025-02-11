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

# Installation directory
INSTALL_DIR=/usr/local/bin

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

# Install target
install: $(TARGET)
	install -m 0755 $(TARGET) $(INSTALL_DIR)

# Uninstall target
uninstall:
	$(RM) $(INSTALL_DIR)/$(TARGET)

# Phony targets (targets not associated with files)
.PHONY: all clean install uninstall
