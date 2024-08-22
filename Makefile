SRC_DIR := src
OBJ_DIR := target
BUILD_DIR := build
PATH_DIR := ~/.local/bin

CC := gcc
CFLAGS := -c -Isrc/headers

SOURCES := $(wildcard $(SRC_DIR)/*.c)
OBJECTS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))
BINARY := $($BUILD_DIR)/VRE

all: $(BUILD_DIR)/VRE

$(BUILD_DIR)/VRE: $(OBJECTS)
	mkdir -p $(dir $@)
	$(CC) $(OBJECTS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BUILD_DIR)

install: $(BINARY)
	mkdir -p $(dir $@)
	cp $< $(PATH_DIR)/VRE
	chmod +x $(PATH_DIR)/VRE
	echo "You must add ~/.local/bin to your PATH for VRE to work"


.PHONY: all clean