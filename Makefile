export I_DIR := $(PWD)/include
export TOPLEVEL := VGA_CTL
all:
	$(MAKE) bench


run text: bench
	./bench/cpp/main_tb

graphics: bench
	./bench/cpp/main_tb -g

bitmap: bench
	./bench/cpp/main_tb -i ./test.data

more:	test
.PHONY: rtl demo bench
SUBMAKE := $(MAKE) --no-print-directory -C

.PHONY: clean
clean:
	$(SUBMAKE) bench/cpp		clean
	$(SUBMAKE) bench/rtl		clean
	$(MAKE) 			VGA_CTL_clean

demo:
	$(SUBMAKE) bench/rtl/

bench: demo
	cp -f $(PWD)/test.data bench/cpp/ 
	$(SUBMAKE) bench/cpp/

rtl: test

FBDIR := .
VDIRFB:= $(FBDIR)/obj_dir

.PHONY: VGA_CTL
test: VGA_CTL
VGA_CTL: $(VDIRFB)/VVGA_CTL__ALL.a

VOBJ := obj_dir
ifeq ($(VERILATOR_ROOT),)
VERILATOR := verilator
else
VERILATOR := $(VERILATOR_ROOT)/bin/verilator
endif
VFLAGS := -Wno-fatal --bbox-sys --coverage --top-module $(TOPLEVEL) --MMD --trace -cc *.v

$(VDIRFB)/VVGA_CTL__ALL.a: $(VDIRFB)/VVGA_CTL.h
$(VDIRFB)/VVGA_CTL__ALL.a: $(VDIRFB)/VVGA_CTL.cpp
$(VDIRFB)/VVGA_CTL__ALL.a: $(VDIRFB)/VVGA_CTL.mk
$(VDIRFB)/VVGA_CTL.h: VGA_CTL.v


$(VDIRFB)/V%.cpp $(VDIRFB)/V%.h $(VDIRFB)/V%.mk: $(FBDIR)/%.v
	$(VERILATOR) $(VFLAGS)

$(VDIRFB)/V%__ALL.a: $(VDIRFB)/V%.mk
	$(MAKE) --no-print-directory --directory=$(VOBJ) -f V$*.mk

.PHONY: VGA_CTL_clean
VGA_CTL_clean:
	rm -rf $(VDIRFB)/
	rm -rf $(I_DIR)/

#
# Note Verilator's dependency created information, and include it here if we
# can
DEPS := $(wildcard $(VDIRFB)/*.d)

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(DEPS),)
include $(DEPS)
endif
endif
