#include "TestClass.h"
#include <iostream>

void main() {
	TestClass  test(10);
	test.print();      // 10�ƕ\�������

	TestClass* pTest = new TestClass(20);
	pTest->print();    // 20�ƕ\�������
	delete pTest;//��������Ȃ��ƃ������Ɏc��

	char a[10];
	std::cin >> a;
}