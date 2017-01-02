// Bitter.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	uint16_t a = 4;
	cout << bitset<16>(a) << endl;
	cout << bitset<16>(-a) << endl;
	uint16_t mask = 1 << 9;
	cout << bitset<16>(mask) << endl;
	cout << bitset<16>(a&-a) << endl;
	char buf[23];
	cin >> buf;


    return 0;
}

