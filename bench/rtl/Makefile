

all:	test
FBDIR := .
VDIRFB:= $(FBDIR)/obj_dir

.PHONY: chartest
test: chartest
chartest: $(VDIRFB)/Vchartest__ALL.a

VOBJ := obj_dir
SUBMAKE := $(MAKE) --no-print-directory --directory=$(VOBJ) -f
ifeq ($(VERILATOR_ROOT),)
VERILATOR := verilator
else
VERILATOR := $(VERILATOR_ROOT)/bin/verilator
endif
VFLAGS := -Wno-fatal --top-module chartest --MMD --trace ../../*.v -cc

$(VDIRFB)/Vchartest__ALL.a: $(VDIRFB)/Vchartest.h
$(VDIRFB)/Vchartest__ALL.a: $(VDIRFB)/Vchartest.cpp
$(VDIRFB)/Vchartest__ALL.a: $(VDIRFB)/Vchartest.mk
$(VDIRFB)/Vchartest.h: chartest.v

$(VDIRFB)/V%.cpp $(VDIRFB)/V%.h $(VDIRFB)/V%.mk: $(FBDIR)/%.v
	$(VERILATOR) $(VFLAGS) $*.v

$(VDIRFB)/V%__ALL.a: $(VDIRFB)/V%.mk
	$(SUBMAKE) V$*.mk

.PHONY: clean
clean:
	rm -rf $(VDIRFB)/

#
# Note Verilator's dependency created information, and include it here if we
# can
DEPS := $(wildcard $(VDIRFB)/*.d)

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(DEPS),)
include $(DEPS)
endif
endif
