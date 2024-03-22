TARGET = $(BIN_DIR)/raytracer

INCLUDE_DIR = ./include
LIB_DIR = ./lib
BIN_DIR = ./bin
SRC_DIR = ./src
OBJ_DIR = ./build/obj

CC = gcc
WARNFLAGS = -Wall -Wextra -Wpedantic
DEFINES =
CCFLAGS = -g $(WARNFLAGS) -I$(INCLUDE_DIR) $(DEFINES)
LDFLAGS = -L$(LIB_DIR)
LDLIBS = -lm

CFILES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(subst $(SRC_DIR), $(OBJ_DIR), $(CFILES:%.c=%.o))

.PHONY: all clean run

all: $(TARGET)

run: $(TARGET)
	@$(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	$(RM) -rf $(TARGET) $(OBJECTS)