// Bitter.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
#include <bitset>

using namespace std;

int Endian()
{
	int x = 1;
	if (*(char *)&x) {
		printf("Little");
	}
	else {
		printf("Big");
	}
	return 0;
}

void EndianConvert() {
	int i = 0x00010b0a;
	cout << bitset<32>(i) << endl;
	i = i << 24 | i << 8 & 0x00ff0000 | i >> 8 & 0x0000ff00 | i >> 24 & 0x000000ff;
	cout << bitset<32>(i) << endl;
}

int main()
{
	char a = 1;//0001
	cout << bitset<1>(a) << endl;
	cout << bitset<2>(a) << endl;
	cout << bitset<4>(a) << endl;
	cout << bitset<8>(a) << endl;
	cout << bitset<16>(a) << endl;
	char b = 0b0010;//0010
	cout << bitset<4>(a & b) << endl;
	cout << bitset<4>(a | b) << endl;
	cout << bitset<4>(a ^ b) << endl;
	cout << bitset<4>(~a) << endl;
	cout << bitset<4>(a << 2) << endl;

	//Endian();
	EndianConvert();

	char buf[23];
	cin >> buf;


    return 0;
}

