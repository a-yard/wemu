wemu_HOME = /home/wsp/StartLinux/wemu
C_SRC = $(wemu_HOME)/wemu_main.cpp \
		$(wemu_HOME)/src/BUS/BUS.cpp \
		$(wemu_HOME)/src/CPU/CPU.cpp \
		$(wemu_HOME)/src/CPU/ISA/riscv32/riscv32.cpp \
		$(wemu_HOME)/src/CPU/ISA/ISA.cpp \
		$(wemu_HOME)/src/Monitor/Monitor.cpp \
		$(wemu_HOME)/src/Monitor/sdb/sdb.cpp \
		$(wemu_HOME)/src/Monitor/sdb/expr.cpp \
		$(wemu_HOME)/src/Monitor/sdb/watchpoint.cpp \
		$(wemu_HOME)/src/SOC/SOC.cpp \
		$(wemu_HOME)/src/Drvice/Memory.cpp \
		$(wemu_HOME)/src/Drvice/BlockDevice.cpp \
		$(wemu_HOME)/src/Drvice/CharacterDevice.cpp \
		$(wemu_HOME)/src/Drvice/Flash.cpp \
		$(wemu_HOME)/src/Drvice/SRAM.cpp \
		$(wemu_HOME)/src/Drvice/MROM.cpp \
		$(wemu_HOME)/src/Drvice/UART.cpp \

LIBS  += -lreadline -lhistory



menuconfig:
	@kconfig-mconf KConfig
	@./KConfig.sh
	
GetColCount:
	@echo "C++ 行数"
	@find . -type f \( -name "*.cpp" -o -name "*.hpp" \) -exec cat {} + | wc -l

run:
	@g++ -w  $(C_SRC) -o $(wemu_HOME)/build/wemu $(LIBS)
	@./build/wemu   -b   $(IMG) 

getTest:
	cp -rf /home/wsp/riscv-tests/isa/rv32* ./test/isa/
	echo $(rv32uiPTests)

# include TestMakefile.mk

runOpenSpi:
	@g++ -w  $(C_SRC) -o $(wemu_HOME)/build/wemu $(LIBS)
	riscv64-unknown-elf-objdump -d  /home/wsp/StartLinux/opensbi/build/platform/generic/firmware/fw_jump.elf > fw_jump.s
	@./build/wemu   -b   /home/wsp/StartLinux/opensbi/build/platform/generic/firmware/fw_jump.bin


makeOpenSBI:
	make -C /home/wsp/StartLinux/opensbi/  PLATFORM=HaiTang CROSS_COMPILE=riscv64-linux-gnu-  FW_DISASM=y