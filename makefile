# Name of the project
PROJ_NAME=main

# .c files
C_SOURCE=$(wildcard *.c)

# # .h files
# H_SOURCE=$(wildcard *.h)

# Object files
OBJ=$(C_SOURCE:.c=.o)

# Compiler
CC=gcc

# Flags for compiler
CC_FLAGS=-W         \
         -Wall      \
         -ansi      \
         -pedantic  \
         -lglut -lGL -lGLU -lSOIL -lm

# Compilation and linking
#
all: $(PROJ_NAME)
  
$(PROJ_NAME): $(OBJ)
	$(CC) -o $@ $^ $(CC_FLAGS)

# %.o: %.c %.h
# 	$(CC) -o $@ $< $(CC_FLAGS)

# main.o: main.c $(H_SOURCE)
# 	$(CC) -o $@ $< $(CC_FLAGS)

clean:
	rm -rf *.o $(PROJ_NAME) *~