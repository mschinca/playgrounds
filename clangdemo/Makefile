# CFLAGS = -march=skylake -O2 -pipe
CFLAGS = -g # debug flags
SRC_PREFIX := src
BUILD_PREFIX := build
SRC_DIR   := $(shell find $(SRC_PREFIX) -type d)
BUILD_DIR := $(patsubst src%,$(BUILD_PREFIX)%,$(SRC_DIR))
SRC       := $(foreach sdir,$(SRC_DIR),$(wildcard $(sdir)/*.c))
OBJ       := $(patsubst src/%.c,$(BUILD_PREFIX)/%.o,$(SRC))
INCLUDES  := $(addprefix -I,$(SRC_DIR))
vpath %.c $(SRC_DIR)

define make-goal
$1/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $$< -o $$@
endef

.PHONY: all checkdirs clean

all: checkdirs build/say_hello.exe

build/say_hello.exe: $(OBJ)
	$(CC) $^ -o $@

checkdirs: $(BUILD_DIR)

$(BUILD_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(BUILD_DIR)

$(foreach bdir,$(BUILD_DIR),$(eval $(call make-goal,$(bdir))))