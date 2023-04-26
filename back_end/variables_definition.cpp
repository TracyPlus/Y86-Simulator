#include"Register.h"

char imemory[800000];
REGS registers;
REG pc, valC, valP, valA, valB, valE, valM, prepc;
char icode, ifun, rA, rB;
int my_stat = 1;
char dstE, dstM, srcA, srcB;
char Cnd = 1;
bool zf = 1, of = 0, sf = 0;
bool imem_error, instr_valid, dmem_error;