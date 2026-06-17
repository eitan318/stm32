SRC_DIR = src
BIN_NAME = output
ELF_FILE = $(BUILD_DIR)/$(BIN_NAME).elf 
BIN_FILE = $(BUILD_DIR)/$(BIN_NAME).bin 
BUILD_DIR = build
O_DIR = $(BUILD_DIR)/out

SRCS = $(SRC_DIR)/*.c

.PHONY: all setup build clean flash

all: build

setup:
	# install deps
	sudo apt install gcc-arm-none-eabi binutils-arm-none-eabi build-essential openocd

build:
	mkdir -p $(BUILD_DIR)
	mkdir -p $(O_DIR)
	# compile .c files to .o files
	for src in $(SRCS); do \
		filename=$$(basename $$src .c); \
		arm-none-eabi-gcc -c -mcpu=cortex-m7 -mthumb -Iinclude\
			-Os -g3 -Wall -fdata-sections -ffunction-sections \
			$$src -o $(O_DIR)/$$filename.o; \
	done

	# link .o files to .elf
	arm-none-eabi-gcc $(O_DIR)/*.o -mcpu=cortex-m7 -mthumb -T stm32h7x.ld \
		--specs=nano.specs -Wl,--gc-sections -o $(ELF_FILE) 

	# convert elf to bin
	arm-none-eabi-objcopy -O binary $(ELF_FILE) $(BIN_FILE) 

clean: 
	# rm outputs
	rm -rf $(O_DIR) $(ELF_FILE) $(BIN_FILE) 

flash: $(ELF_FILE)
	# Use OpenOCD to flash the binary
	openocd -f interface/stlink.cfg -f target/stm32h7x.cfg \
	-c "program $(ELF_FILE) verify reset exit"


