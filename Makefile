# Define the compiler and compiler flags
CC = gcc
CFLAGS = -Wall -O2

# Define the source files and the executable name
SRCS = main.c get_time.c init.c
OBJS = $(SRCS:.c=.o)
ASM = $(SRCS:.c=.s)

EXECUTABLE = myprogram

# Define header file dependencies
DEPS = func.h

# Default target
all: $(EXECUTABLE) $(ASM)

# Build the executable
$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Compile source files into object files
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $<

# Compile source files into human-readable assembly files
%.s: %.c
	$(CC) $(CFLAGS) -S $<

# Clean up the generated files
clean:
	rm -f $(OBJS) $(ASM) $(EXECUTABLE)

# Define a target to run the program multiple times
run_MegaByte: $(EXECUTABLE)
	@echo "Running the program 5 times:"
	@for i in 1 2 3 4 5; do \
		echo "Run $$i:"; \
		./$(EXECUTABLE) 1000000; \
	done

run_GigaByte: $(EXECUTABLE)
	@echo "Running the program 5 times:"
	@for i in 1 2 3 4 5; do \
		echo "Run $$i:"; \
		./$(EXECUTABLE) 1000000000; \
	done
