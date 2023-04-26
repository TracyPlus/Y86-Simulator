#pragma once
#ifndef _GUARD_MEMORY_H_
#define _GUARD_MEMORY_H_
#include"variables_declaration.h"

//generate addr/data.
//read valM or write valE
//calculate stat:???????no need to write before?

void memory();
long long mem_addr();
char* mem_data();
bool mem_read();
bool mem_write();
void set_stat();
//bool check_dmem_error();

#endif