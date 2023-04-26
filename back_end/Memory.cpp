#include"Memory.h"

void memory();
long long mem_addr();
char* mem_data();
bool mem_read();
bool mem_write();
void set_stat();

void memory() {
    long long addr = mem_addr();
    char* data = mem_data();
   
    
    dmem_error = addr > 799990 || addr < 0;
    if (mem_read()) {       
        valM.write_data(imemory+addr);//the way to call write_val
       
    }
    else if (mem_write()) {
        for (int i = 0; i < 8; i++) {
            imemory[addr + i] = data[i];
        }
       
    }
    set_stat();
}

long long mem_addr() {
    switch (icode) {
    case(4):
    case(5):
    case(8):
    case(0xA):return valE.get_data_ll();
    case(9):
    case(0xB):return valA.get_data_ll();
    default:return 0;
    }
}

char* mem_data() {
    switch (icode) {
    case(4):
    case(0xA): {
        return valA.get_data_ch();
    }
    case(8): {
      
        return valP.get_data_ch();
        
    }
    default:return 0;
    }
}

bool mem_read() {
    switch (icode) {
    case(5):
    case(9):
    case(0xB):return true;
    default:return false;
    }
}

bool mem_write() {
    switch (icode) {
    case(4):
    case(8):
    case(0xA):return true;
    default:return false;
    }
}

void set_stat() {
    if (imem_error || dmem_error) my_stat = 3;
    else if (!instr_valid) my_stat = 4;
    else if (!icode) my_stat = 2;
    else my_stat = 1;
}
