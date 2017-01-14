#include <stdio.h>
#include <iostream>

//for•¶
int func(short e) {
	int result = 1;
	for (short i = 1; i <= e;i++) {
		result *= i;
	}
	return result;
}

//goto•¶
int func_old(short e) {
	int result = 1;
	short i = 1;
loop1:
	result *= i;
	i++;
	if (i <= e) goto loop1;
	return result;
}

//In Line Asm
int func_asm(short e) {
	_asm {
		MOV EAX,1//result = 1
		MOV ECX,1//i = 0
	loop1:
		MUL ECX
		INC ECX
		CMP ECX,DWORD PTR e
		JBE loop1
	}
}

int main(void) {
	int data = func_old(10);
	printf("Result : %d",data);

	char aga[10];
	std::cin >> aga;

	return 0;
}