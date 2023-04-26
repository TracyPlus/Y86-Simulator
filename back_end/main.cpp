#include<iostream>
#include<string>
#include<fstream>
#include"header.h"

using std::cin;
using std::cout;
using std::istream;
using std::ifstream;
using std::string;

void make_imem1(const string&);
void make_imem2(istream&);
void out_mem();
void out_reg();
void out_cc();
void out_order();
void run_out();
int s16toi(const string&);

int main(){
//	ifstream in("asum.yo");
	make_imem2(cin);
	run_out();
}


int s16toi(const string& s) {
	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		int num;
		if (s[i] == ' ') num = 0;
		else if (s[i] >= 'a') num = s[i] - 'a' + 10;
		else num = s[i] - '0';
		sum = sum * 16 + num;
	}
	return sum;
}

void make_imem1(const string& str) {
	string sub = str.substr(2, 3);
	int index = s16toi(sub);
	string order = str.substr(7, 20);
	if (str[7] != ' ') {
		for (int j = 0; j < 10; j++) {
			if (order[j] != ' ') {
				string ord = order.substr(j * 2, 2);
				imemory[j + index] = s16toi(ord);
			}
		}
	}
}

void make_imem2(istream& it){
    string str;
    while(getline(it,str)){
        make_imem1(str);
    }
}

void out_mem() {
	printf("\t\t\"MEM\":{\n");
	for (int i=0;i<799990;i=i+8)
	{
		int sign=0;
		Data o_mem;
		for (int j = 0; j < 8; j++) {
			o_mem.ch[j] = imemory[i + j];
		}
		long long o_val = o_mem.ll;
		
		if (o_val != 0) {
			if (!i)
				printf("\t\t\t\"%lld\":%lld", i, o_val);
			else {
				printf(",\n");
				printf("\t\t\t\"%lld\":%lld", i, o_val);
			}
		}
	}
	printf("\n\t\t},\n");
}

void out_reg() {
	printf("\t\t\"REG\":{\n");
	printf("\t\t\t\"rax\":%lld,\n", registers.get_reg(0).get_data_ll());
	printf("\t\t\t\"rcx\":%lld,\n", registers.get_reg(1).get_data_ll());
	printf("\t\t\t\"rdx\":%lld,\n", registers.get_reg(2).get_data_ll());
	printf("\t\t\t\"rbx\":%lld,\n", registers.get_reg(3).get_data_ll());
	printf("\t\t\t\"rsp\":%lld,\n", registers.get_reg(4).get_data_ll());
	printf("\t\t\t\"rbp\":%lld,\n", registers.get_reg(5).get_data_ll());
	printf("\t\t\t\"rsi\":%lld,\n", registers.get_reg(6).get_data_ll());
	printf("\t\t\t\"rdi\":%lld,\n", registers.get_reg(7).get_data_ll());
	printf("\t\t\t\"r8\":%lld,\n", registers.get_reg(8).get_data_ll());
	printf("\t\t\t\"r9\":%lld,\n", registers.get_reg(9).get_data_ll());
	printf("\t\t\t\"r10\":%lld,\n", registers.get_reg(10).get_data_ll());
	printf("\t\t\t\"r11\":%lld,\n", registers.get_reg(11).get_data_ll());
	printf("\t\t\t\"r12\":%lld,\n", registers.get_reg(12).get_data_ll());
	printf("\t\t\t\"r13\":%lld,\n", registers.get_reg(13).get_data_ll());
	printf("\t\t\t\"r14\":%lld\n", registers.get_reg(14).get_data_ll());
	printf("\t\t},\n");
}

void out_cc() {
	printf("\t\t\"CC\":{\n");
	printf("\t\t\t\"ZF\":%d,\n", zf);
	printf("\t\t\t\"SF\":%d,\n", sf);
	printf("\t\t\t\"OF\":%d\n", of);
	printf("\t\t},\n");
}
/*
void out_order() {
	printf("\t\t\"ORDER\":\"");
	long long start = prepc.get_data_ll();
	long long ending = pc.get_data_ll();
	long long size = (ending - start) / 2;
	int order = icode * 16 + ifun;
	
	string reg_name[15] = { "%rax", "%rcx","%rdx","%rbx","%rsp","%rbp","%rsi","%rdi","%r8","%r9","%r10","%r11","%r12","%r13","%r14" };

//	printf("%x", order);
	switch (order) {
	case(0x00):printf("halt"); break;
	case(0x10):printf("nop"); break;

	case(0x20):printf("rrmovq %s %s",reg_name[rA],reg_name[rB]); break;
	case(0x21):printf("cmovle %s %s",reg_name[rA], reg_name[rB]); break;
	case(0x22):printf("cmovl %s %s", reg_name[rA], reg_name[rB]); break;
	case(0x23):printf("cmove %s %s", reg_name[rA], reg_name[rB]); break;
	case(0x24):printf("cmovne %s %s", reg_name[rA], reg_name[rB]); break;
	case(0x25):printf("cmovge %s %s", reg_name[rA], reg_name[rB]); break;
	case(0x26):printf("cmovg %s %s", reg_name[rA], reg_name[rB]); break;
	
	case(0x30):printf("irmovq \$%lld %s", valC.get_data_ll(), reg_name[rB]); break;
	case(0x40):printf("rmmovq %s (%s)", reg_name[rA], reg_name[rB]); break;
	case(0x50):printf("mrmovq (%s) %s", reg_name[rA], reg_name[rB]); break;

	case(0x60):printf("addq %s %s", reg_name[rA], reg_name[rB]); break;
	case(0x61):printf("subq %s %s", reg_name[rA], reg_name[rB]); break;
	case(0x62):printf("andq %s %s", reg_name[rA], reg_name[rB]); break;
	case(0x63):printf("xorq %s %s", reg_name[rA], reg_name[rB]); break;

	case(0x70):printf("jmp %lld",valC.get_data_ll()); break;
	case(0x71):printf("jle %lld", valC.get_data_ll()); break;
	case(0x72):printf("jl %lld", valC.get_data_ll()); break;
	case(0x73):printf("je %lld", valC.get_data_ll()); break;
	case(0x74):printf("jne %lld", valC.get_data_ll()); break;
	case(0x75):printf("jge %lld", valC.get_data_ll()); break;
	case(0x76):printf("jg %lld", valC.get_data_ll()); break;

	case(0x80):printf("call %lld", valC.get_data_ll()); break;
	case(0x90):printf("ret");
	case(0xA0):printf("pushq %s", reg_name[rA]); break;
	case(0xB0):printf("popq %s", reg_name[rA]); break;
	default:break;
	}
//	for (int i = 0; i < size; i++) {
//		printf("%x", imemory[start + i]);
//	}
	printf("\"\n");
}
*/
void run_out() {
	cout << "[\n";
	if (my_stat == 1) {
		fetch();
		decode();
		execute();
		memory();
		wback();
		renewpc();
		printf("\t{\n");
		printf("\t\t\"PC\":%lld,\n", pc.get_data_ll());
		out_reg();
		out_mem();
		out_cc();
		printf("\t\t\"STAT\":%d\n", my_stat);
		//		out_order();
		printf("\t}");

	}
	while (my_stat == 1) {
		fetch();
		decode();
		execute();
		memory();
		wback();
		renewpc();
		printf(",\n");
		printf("\t{\n");
		printf("\t\t\"PC\":%lld,\n", pc.get_data_ll());
		out_reg();
		out_mem();
		out_cc();
		printf("\t\t\"STAT\":%d\n", my_stat);
		//		out_order();
		printf("\t}\n");

	}
	printf("]\n");
}