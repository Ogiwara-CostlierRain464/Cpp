// CashTruth.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void WhatIsCast() {
	int i = 100;
	cout << "at:" << &i << "Value:" << i << endl;
}

int main()
{
	WhatIsCast();
	char buf[23];
	cin >> buf;
    return 0;
}

