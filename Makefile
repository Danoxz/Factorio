CC = gcc
CFLAGS = -Wall
SRC_PATH = ./src
BUILD_PATH = ./build
SRC = $(SRC_PATH)/config.c $(SRC_PATH)/snaketools.c $(SRC_PATH)/gametools.c $(SRC_PATH)/input.c $(SRC_PATH)/main.c

.PHONY: all build clean run

all: build
	@echo "Done building!"

build:
	$(CC) $(CFLAGS) $(SRC) -o $(BUILD_PATH)/snake_game -lncurses

clean:
	rm -f $(BUILD_PATH)/*.o
	rm $(BUILD_PATH)/snake_game

run:
	@$(BUILD_PATH)/snake_game