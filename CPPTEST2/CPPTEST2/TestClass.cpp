#include "TestClass.h"
#include<iostream>
using namespace std;

// コンストラクタ
TestClass::TestClass(int n) {
	cout << "コンストラクタ" << n;
	size = n;
}

// デストラクタ
TestClass::~TestClass() {
	cout << "デストラクタ" << size;
}

void TestClass::print() {
	cout << "print" << size;
}