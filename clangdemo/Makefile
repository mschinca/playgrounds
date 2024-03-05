CFLAGS = -O3
SRC_PREFIX := src
BUILD_PREFIX := build
MODULES   := lib customlibs
SRC_DIR   := $(SRC_PREFIX) $(addprefix $(SRC_PREFIX)/,$(MODULES))
BUILD_DIR := $(BUILD_PREFIX) $(addprefix $(BUILD_PREFIX)/,$(MODULES))
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