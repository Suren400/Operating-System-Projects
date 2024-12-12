# Toolchain
CC = riscv64-unknown-elf-gcc
LD = riscv64-unknown-elf-ld
OBJCOPY = riscv64-unknown-elf-objcopy

# Directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

# Source Files
PROGRAMS = ProgramA.c ProgramB.c
KERNEL = kernel.c paging.c syscalls.c process.c interrupts.c

#object files
OBJECTS = $(addprefix $(BUILD_DIR)/, $(PROGRAMS:.c=.o) $(KERNEL:.c=.o))

# Linker Script
LINKER_SCRIPT = linker.ld

# Output File
OUTPUT = main.elf

# Compiler Flags
CFLAGS = -Wall -O2 -g -I$(INCLUDE_DIR) -march=rv64imac -mabi=lp64

# Build
all: $(OUTPUT)

$(OUTPUT): $(OBJECTS)
	$(LD) -T $(LINKER_SCRIPT) -o $(BUILD_DIR)/$(OUTPUT) $(OBJECTS)
	$(OBJCOPY) -O binary $(BUILD_DIR)/$(OUTPUT) $(BUILD_DIR)/$(OUTPUT).bin

# Compile .c files to .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/$(OUTPUT) $(BUILD_DIR)/*.bin
