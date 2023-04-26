#include"Register.h"

union Data;
class REG;
class REGS;

char* REG::get_data_ch(){
    return data.ch;
}

long long REG::get_data_ll() {
    return data.ll;
}

bool REG::write_data(const char* d){
    for(int i=0;i!=8;i++)
        data.ch[i]=d[i];
    return true;
}

bool REG::write_data(long long d){
    data.ll=d;
    return true;
}

REG& REG::operator=(REG r){
    write_data(r.get_data_ch());
    return *this;
}

REG REGS::get_reg(int index){
    return reg[index];
}

bool REGS::write_data(int index,const char* d){
    reg[index].write_data(d);
    return true;
}

bool REGS::write_data(int index,REG& r){
    reg[index]=r;
    return true;
}


