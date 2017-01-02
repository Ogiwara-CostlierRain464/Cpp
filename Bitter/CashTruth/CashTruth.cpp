// CashTruth.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
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

