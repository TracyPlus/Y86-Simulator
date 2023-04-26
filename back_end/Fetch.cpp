#include"Fetch.h"

void fetch();
bool check_imem_error();
bool check_instr_valid();
bool need_regids();
bool need_valC();

void fetch() {
    //1.read from pc
    //2.set icode\ifun
    //3.set valP,valC
 //   std::cout << "fetch.1"<<endl;
    imem_error = check_imem_error();
    if (imem_error) my_stat = 2;
    else {
//        cout << "fetch.2" << endl;
        icode = 0xF & (imemory[pc.get_data_ll()] >> 4);
        ifun = 0xF & imemory[pc.get_data_ll()];
        instr_valid = check_instr_valid();
//        cout << "instr:" << instr_valid << endl;;
        if (!instr_valid) {
            my_stat = 3;
        }
        else {//set rA,rB,valC,valP,stat;      
            my_stat = 1;
            if (need_regids()) {
                rA = 0xF & (imemory[pc.get_data_ll() + 1] >> 4);
                rB = 0xF & imemory[pc.get_data_ll() + 1];
                if (need_valC()) {
                    valC.write_data(imemory + pc.get_data_ll() + 2);
                    valP.write_data(pc.get_data_ll() + 10);
                }
                else {
                    valP.write_data(pc.get_data_ll() + 2);
                }
            }
            else {
                if (need_valC()) {
                    valC.write_data(imemory + pc.get_data_ll() + 1);
                    valP.write_data(pc.get_data_ll() + 9);
                }
                else {
                    valP.write_data(pc.get_data_ll() + 1);//for ret
                }
            }
        }
    }
}

bool check_imem_error() {
    if (pc.get_data_ll() > 799990 || pc.get_data_ll() < 0) return true;
    else return false;
}

bool check_instr_valid() {

    if (icode > 0xC) return false;
    switch (icode) {
        case(2): {
        if (ifun > 6) return false; break;
        }
        case(6): {
        if (ifun > 3) return false; break;
        }
        case(7): {
        if (ifun > 6) return false; break;
        }
        default: {
        if (ifun != 0) return false;
        else return true;
        }
    }
    return true;
}

bool need_regids() {
    switch (icode) {
    case(2):
    case(6):
    case(0xA):
    case(0xB):
    case(3):
    case(4):
    case(5):
    case(0xC):return true;
    default:return false;
    }
}

bool need_valC() {
    switch (icode) {
    case(3):
    case(4):
    case(5):
    case(7):
    case(8):
    case(0xC):return true;
    default:return false;
    }
}
