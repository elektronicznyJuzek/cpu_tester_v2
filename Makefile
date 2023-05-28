# Compiler
CC := gcc

# Compiler flags
CFLAGS := -Wall -Wextra -g

# Directories
SRCDIR := src
INCDIR := include
BINDIR := bin

# Source files
SRCS := $(wildcard $(SRCDIR)/*.c)

# Object files
OBJS := $(patsubst $(SRCDIR)/%.c, $(BINDIR)/%.o, $(SRCS))

# Executable
TARGET := $(BINDIR)/cpu_usage_app

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Compile source files
$(BINDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# Clean the generated files
clean:
	rm -f $(OBJS) $(TARGET)
