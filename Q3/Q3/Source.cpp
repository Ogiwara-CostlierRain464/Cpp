#include <iostream>

/*void FizzBuzz(char e) {
	for (char i = 1; i <= e;i++) {
		if (i%15==0) {
			printf("FizzBuzz ");
			continue;
		}
		if (i%5==0) {
			printf("Buzz ");
			continue;
		}
		if (i%3==0) {
			printf("Fizz ");
			continue;
		}
		printf("%d ",i);
	}
}*/

void FizzBuzz_old(char e) {
	char i = 1;
loop1:
	if (i % 15 == 0) {
		printf("FizzBuzz ");
	}else if (i % 5 == 0) {
		printf("Buzz ");
	}else if (i % 3 == 0) {
		printf("Fizz ");
	}else {
		printf("%d ", i);
	}
	i++;
	if (i <= e) goto loop1;
}

char Fizz[] = "Fizz ";
char Buzz[] = "Buzz ";
char FizzBuzz[] = "FizzBuzz ";

void FizzBuzz_asm(char e) {
	_asm{
		MOV EBX,1//i
		MOV ECX,DWORD PTR e
	loop1:
		//i%15
		MOV EAX,15
		XOR EDX,EDX
		DIV EBX
		CMP EDX,0
		JE FB
		//i%5
		MOV EAX, 5
		XOR EDX, EDX
		DIV EBX
		CMP EDX, 0
		JE B
		//i%3
		MOV EAX, 3
		XOR EDX, EDX
		DIV EBX
		CMP EDX, 0
		JE F
		//printf i
		MOV EAX,EBX
		PUSH EAX
		CALL printf
		POP EDX
		JMP END
	FB:
		MOV EAX, offset  FizzBuzz
		PUSH EAX
		CALL printf
		POP EDX
		JMP END
	F:
		MOV EAX, offset  Fizz
		PUSH EAX
		CALL printf
		POP EDX
		JMP END
	B:
		MOV EAX, offset  Buzz
		PUSH EAX
		CALL printf
		POP EDX
		JMP END
	END:
		INC EBX
		CMP EBX,ECX
		JBE loop1
	}
}

//FizzBuzz
int main() {
	FizzBuzz_asm(20);

	char a[12];
	std::cin >> a;

	return 0;
}