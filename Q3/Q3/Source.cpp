#include <iostream>

void FizzBuzz(char e) {
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
}

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

//FizzBuzz
int main() {
	FizzBuzz_old(20);

	char a[12];
	std::cin >> a;

	return 0;
}