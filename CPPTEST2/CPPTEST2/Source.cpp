#include "TestClass.h"
#include <iostream>

void main() {
	TestClass  test(10);
	test.print();      // 10と表示される

	TestClass* pTest = new TestClass(20);
	pTest->print();    // 20と表示される
	delete pTest;//これをしないとメモリに残る

	char a[10];
	std::cin >> a;
}