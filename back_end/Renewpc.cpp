#include"Renewpc.h"

void renewpc();

void renewpc() {
    if (my_stat == 1) {
        prepc = pc;
        switch (icode) {
        case(8):pc = valC; break;
        case(7): {
            if (Cnd) pc = valC;
            else pc = valP;
            break;
        }
        case(9):pc = valM; break;
        default:pc = valP;
        }
    }
}