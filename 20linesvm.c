#include"stdio.h"
int mem[1024] = {0}, pc = 0;
void opr(int op, int n, int x, int y) {
	if(op==1) mem[n] = mem[x] & mem[y];
	if(op==2) mem[n] = mem[x] | mem[y];
	if(op==3) mem[n] = x;
}
void jmp(int a, int b) {
	if(mem[a]) pc = b;
}
void io(int port, int arg) {
	if(port==1) putchar(mem[arg]);
	if(port==2) mem[arg] = getchar();
}
void excute(int* code) {
	if(*code==0) return;
	if(*code==1) opr(code[1], code[2], code[3], code[4]), excute(code+5);
	if(*code==2) jmp(code[1], code[2]), excute(code+3);
	if(*code==3) io(code[1], code[2]), excute(code+3);
}
