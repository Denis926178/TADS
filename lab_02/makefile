C = gcc
OUT_DIR = ./out
SRC_DIR = ./src
CFLAGS = -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla 
LMFLAG = -lm
MAKEOUT := $(shell mkdir ./out; false)

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OUT_DIR)/%.o)

INCLUDES = -I inc

UNIT_TEST_CFLAGS = -lcheck

UNIT_TEST_DIR = ./unit_tests
UNIT_TEST_SRC = $(wildcard $(UNIT_TEST_DIR)/*.c)
UNIT_TEST_OBJ = $(UNIT_TEST_SRC:$(UNIT_TEST_DIR)/%.c=$(OUT_DIR)/%.o)
OBJ_FOR_UNIT = $(OBJ) $(UNIT_TEST_OBJ)
NEW_OBJ_FOR_UNIT = $(filter-out ./out/main.o,$(OBJ_FOR_UNIT))

$(OUT_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(OUT_DIR)/%.o: $(UNIT_TEST_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

app.exe: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

unit_tests.exe: $(NEW_OBJ_FOR_UNIT)
	$(CC) -o $@ $^ $(UNIT_TEST_CFLAGS) $(LMFLAG)

unit:
	./unit_tests.exe

clean:
	rm -rf $(OUT_DIR)/*.o app.exe unit_tests.exe

.PHONY: clean unit
