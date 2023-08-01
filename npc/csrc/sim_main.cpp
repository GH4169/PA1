#include <stdio.h>
#include <stdlib.h>
#include "Vtop.h"
#include <verilated.h>

vluint64_t sim_time = 0;
int main(int argc, char** argv) {
	VerilatedContext* contextp = new VerilatedContext;
	contextp->commandArgs(argc, argv);	
	Vtop* dut = new Vtop{contextp};
	
	while (!contextp->gotFinish()){
		int a = rand() & 1;
		int b = rand() & 1;
		dut->a = a;
		dut->b = b;
		dut->eval();
		printf("a = %d, b = %d, f = %d\n", a, b, dut->f);
		assert(dut->f == (a ^ b));
	}	
}
