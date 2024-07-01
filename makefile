# Compiler options
CC = gcc
CFLAGS = -Wall -g
INCLUDES = -I.

# Directories
BINDIR = bin

# Source files
SOURCES = value.c tensor.c neuron.c layer.c main.c

# Object files
OBJECTS = $(SOURCES:%.c=$(BINDIR)/%.o)

# Executable
EXECUTABLE = $(BINDIR)/main

# Default target
all: $(EXECUTABLE)

# Compile source files into objects
$(BINDIR)/%.o: %.c | $(BINDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Link objects into executable
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

# Create bin directory if it doesn't exist
$(BINDIR):
	mkdir -p $(BINDIR)

# Clean target
clean:
	rm -rf $(BINDIR)

# Phony targets
.PHONY: all clean
