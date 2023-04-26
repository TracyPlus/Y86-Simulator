#pragma once
#ifndef _GUARD_DECLARATION_H_
#define _GUARD_DECLARATION_H_

#include"Register.h"

extern char imemory[800000];
extern REGS registers;
extern REG pc, valC, valP, valA, valB, valE, valM, prepc;
extern char icode, ifun, rA, rB;
extern int my_stat;
extern char dstE, dstM, srcA, srcB;
extern char Cnd;
extern bool zf, of, sf;
extern bool imem_error, instr_valid, dmem_error;

#endif