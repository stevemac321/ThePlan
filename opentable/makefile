# Define compiler and flags
CC = clang
CFLAGS = -std=c17 -g
MACROS = -DHEAP_SIZE_BYTES=4096

# Define source and object files
SRCS = heap.c functor.c algo.c open_table.c main.c
OBJS = $(SRCS:.c=.o)
TARGET = test.exe

# Default target
all: $(TARGET)

# Debug target
dbg: $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(MACROS) -o $(TARGET) $(OBJS)

# Compile each source file to an object file
%.o: %.c
	$(CC) $(CFLAGS) $(MACROS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all dbg clean
