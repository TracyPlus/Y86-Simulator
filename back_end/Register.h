#pragma once
#ifndef _GUARD_REGISTER_H
#define _GUARD_REGISTER_H
using namespace std;

union Data;
class REG;
class REGS;

union Data{
    char ch[8];
    long long ll;
};

//basic reg unit or variable unit.
class REG{
public:
    REG(){data.ll=0;}
    char* get_data_ch();
    long long get_data_ll();
    bool write_data(const char*);
    bool write_data(long long);
    REG& operator=(REG r);
private:
    Data data;
};

class REGS{
public:
    REG get_reg(int);
    bool write_data(int, const char*);
    bool write_data(int, REG&);
private:
    REG reg[15];
};

#endif 
