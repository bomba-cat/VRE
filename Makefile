SRC_DIR := src
OBJ_DIR := target
BUILD_DIR := build

CC := gcc
CFLAGS := -c -Isrc/headers

SOURCES := $(wildcard $(SRC_DIR)/*.c)
OBJECTS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

all: $(BUILD_DIR)/VRE

$(BUILD_DIR)/VRE: $(OBJECTS)
	mkdir -p $(dir $@)
	$(CC) 					$(OBJECTS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BUILD_DIR)

.PHONY: all clean