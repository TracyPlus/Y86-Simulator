#include"Decode.h"

void decode();
char get_srcA();
void set_valA();
char get_srcB();
void set_valB();


void decode()
{
    set_valA();
    set_valB();
}

char get_srcA() {
    switch (icode) {
    case(2):
    case(4):
    case(6):
    case(0xA):return rA;
    case(9):
    case(0xB):return 4;
    default:return 0xF;
    }
}

void set_valA() {
    srcA = get_srcA();

    if (srcA != 0xF) {
        valA = registers.get_reg(srcA);
    }
    else {
        REG none;
        valA = none;
    }
}

char get_srcB() {
    switch (icode) {
    case(4):
    case(5):
    case(0xC):
    case(6):return rB;
    case(8):
    case(9):
    case(0xA):
    case(0xB):return 4;
    default:return 0xF;
    }

}

void set_valB() {
    srcB = get_srcB();

    if (srcB != 0xF) {
        valB = registers.get_reg(srcB);
    }
    else {
        REG none;
        valB = none;
    }
}
