all:
	@echo "Write this Makefile by your self."

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator --cc --exe -Wall --build vsrc/top.v csrc/sim_main.cpp
	obj_dir/Vtop
include ../Makefile
