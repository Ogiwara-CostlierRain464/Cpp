#include "TestClass.h"
#include <iostream>

void main() {
	TestClass  test(10);
	test.print();      // 10‚Æ•\Ž¦‚³‚ê‚é

	TestClass* pTest = new TestClass(20);
	pTest->print();    // 20‚Æ•\Ž¦‚³‚ê‚é
	delete pTest;//‚±‚ê‚ð‚µ‚È‚¢‚Æƒƒ‚ƒŠ‚ÉŽc‚é

	char a[10];
	std::cin >> a;
}