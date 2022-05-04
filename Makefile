CC = gcc
OBJS = src/*.c 
OBJ = bin/fbyte
CFLAGS = 
LIBS =

all: build run

build:
	@$(CC) $(OBJS) $(CFLAGS) $(LIBS) -o $(OBJ)

run:
	@./$(OBJ)

clean:
	@rm ./$(OBJ)
	@echo "Cleaned!"