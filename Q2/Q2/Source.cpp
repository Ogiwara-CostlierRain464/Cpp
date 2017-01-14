#include <iostream>
#define num short


num sum(num e) {//?
	num sum = 0;
	num dig;
	while (e) {
		dig = e % 10;
		sum = sum + dig;
		e = e / 10;
	}
	return sum;
}

num sum_old(num e) {
	num q;
	num p;
loop1:
	q = e / 10;
	p = e % 10;
	e = q + p;
	if (e >= 10) goto loop1;
	return e;
}

num sum_asm(num e) {
	_asm {
		MOV ECX,DWORD PTR e
	loop1:
		MOV EAX, 10
		XOR EDX,EDX//EDX‚ğ0‚É‚µ‚È‚­‚Ä‚Í‚È‚ç‚È‚¢
		DIV ECX
		XOR ECX,ECX
		ADD ECX,EAX
		ADD ECX,EDX
		CMP ECX,10
		JAE loop1
		MOV EAX,ECX
	}
}

num main(void) {

	num data = sum_asm(3257);
	printf("%d",data);

	char a[20];
	std::cin >> a;

	return 0;
}