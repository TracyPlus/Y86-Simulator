#include"Wback.h"

void wback();
char get_dstE();
char get_dstM();
void write_dstE();
void write_dstM();


void wback() {
    write_dstE();
    write_dstM();
}

void write_dstE() {
    char dstE = get_dstE();
 
    if (dstE != 0xF) {
       
        registers.write_data(dstE, valE);
      
    }
}

void write_dstM() {
    char dstM = get_dstM();
   
    if (dstM != 0xF) {
        registers.write_data(dstM, valM);
      
    }
}

char get_dstE() {
    switch (icode) {
    case(2): {
        if (Cnd) return rB;
        else return 0xF;
        break;
    }
    case(3):
    case(0xC):
    case(6):return rB; break;
    case(8):
    case(9):
    case(0xA):
    case(0xB):return 4;
    default:return 0xF;
    }
}

char get_dstM() {
    switch (icode) {
    case(5):
    case(0xB):return rA; break;
    default:return 0xF;
    }
}
