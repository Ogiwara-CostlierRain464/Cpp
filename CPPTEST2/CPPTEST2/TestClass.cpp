#include "TestClass.h"
#include<iostream>
using namespace std;

// �R���X�g���N�^
TestClass::TestClass(int n) {
	cout << "�R���X�g���N�^" << n;
	size = n;
}

// �f�X�g���N�^
TestClass::~TestClass() {
	cout << "�f�X�g���N�^" << size;
}

void TestClass::print() {
	cout << "print" << size;
}