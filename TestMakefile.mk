
RESULT = .result
$(shell > $(RESULT))

COLOR_RED   = \033[1;31m
COLOR_GREEN = \033[1;32m
COLOR_NONE  = \033[0m

rv32uiPTests = $(basename $(notdir $(shell ls $(WEMU_HOME)/test/isa/rv32ui-p*)))

rv32uiP: $(addprefix Makefile., $(rv32uiPTests))
	echo $(rv32uiPTests)
	

$(rv32uiPTests): %: Makefile.%

Makefile.%:
	riscv64-unknown-elf-objcopy -O binary test/isa/$* $*.bin
	@/bin/echo -e "NAME = $*\nSRCS = $<\ninclude $${WEMU_HOME}/Makefile" > $@
	@if make -s -f $@ ARCH=$(ARCH) $(MAKECMDGOALS) run IMG=$*.bin ; then \
		printf "[%14s] $(COLOR_GREEN)PASS$(COLOR_NONE)\n" $* >> $(RESULT); \
	else \
		printf "[%14s] $(COLOR_RED)***FAIL***$(COLOR_NONE)\n" $* >> $(RESULT); \
	fi
	-@rm -f Makefile.$*
	-@rm -f $*.bin

	