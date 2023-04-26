#include"Execute.h"

void execute();
long long get_aluA();
long long get_aluB();
char alufun();
bool set_cc();
void set_Cnd();

void execute() {
    long long aluA = get_aluA(), aluB = get_aluB();
   
    long long result;
    switch (alufun()) {
    case(0):result = aluA + aluB; break;
    case(1):result = aluB - aluA; break;
    case(2):result = aluA & aluB; break;
    case(3):result = aluA ^ aluB; break;
    default:result = aluA + aluB;
    }
    valE.write_data(result);
    if (set_cc()) {
       
        zf = !result;
        of = (aluA ^ aluB) < 0 && (aluB ^ result) < 0;//溢出判断：负-正=正or正-负=负
        sf = result < 0;
    }
    set_Cnd();
}

long long get_aluA() {
    switch (icode) {
    case(2):
    case(6):return valA.get_data_ll();
    case(3):
    case(4):
    case(0xC):
    case(5):return valC.get_data_ll();
    case(8):
    case(0xA):return -8;
    case(9):
    case(0xB):return 8;
    default:return 0;//不需要aluA
    }
}

long long get_aluB() {
    switch (icode) {
    case(4):
    case(5):
    case(6):
    case(8):
    case(9):
    case(0xA):
    case(0xC):
    case(0xB):return valB.get_data_ll();
    case(2):
    case(3):return 0;
    default:return 0;//不需要aluB
    }
}

char alufun() {
    if (icode == 6) return ifun;
    else return 0;
}

bool set_cc() {
    if (icode == 6 || icode == 0xC) return true;
    else return false;
}

void set_Cnd() {
    if (icode == 2||icode == 7) {//code must be 2? or it wont't call set_Cnd().
       
        switch (ifun) {
        case(1):Cnd = (sf ^ of) | zf; break;
        case(2):Cnd = sf ^ of; break;
        case(3):Cnd = zf; break;
        case(4):Cnd = !zf; break;
        case(5):Cnd = !(sf ^ of); break;
        case(6):Cnd = (!(sf ^ of)) & (!zf); break;
        default:Cnd = 1;
        }
    }
    else
        Cnd = 1;
}