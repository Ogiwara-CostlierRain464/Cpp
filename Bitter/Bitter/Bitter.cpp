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

void ShortEndian() {
	short s = 0x0400;//0000
	cout << bitset<16>(s) << endl;
	s = s << 8 | s >> 8;
	cout << bitset<16>(s) << endl;
}

void WhatIsCast() {
	char c = 20;
	printf("at:[%p]Val:[%d]\n",&c,c);
	cout << "Raw:" << bitset<sizeof(char)*8>(c) << endl;//00010100
	short s = c;
	printf("at:[%p]Val:[%d]\n", &s, s);
	cout << "Raw:" << bitset<sizeof(short)*8>(s) << endl;//00000000 00010100
	short s2 = 1000;
	printf("at:[%p]Val:[%d]\n", &s2, s2);
	cout << "Raw:" << bitset<sizeof(short) * 8>(s2) << endl;//00000011 11101000
	char c2 = s2;
	printf("at:[%p]Val:[%d]\n", &c2, c2);
	cout << "Raw:" << bitset<sizeof(char)*8>(c2) << endl;//11101000
}

void WhatIsVoidp() {
	int *p1;
	int i = 333333;
	p1 = &i;
	printf("POINTER at:[%p] TrueVal:[%p] Val:[%d]\n",&p1,p1,*p1);
	printf("at:[%p]Val:[%d]\n", &i, i);

	void* vp;
	int v = 202020;
	vp = &v;
	printf("POINTER at:[%p] TrueVal:[%p] Val:[%d]\n", &vp, vp, *((int*)vp));
	printf("at:[%p]Val:[%d]\n", &v, v);
}

int main()
{
	/*char a = 1;//0001
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
	//EndianConvert();
	ShortEndian();*/

	//WhatIsCast();
	WhatIsVoidp();


	char buf[23];
	cin >> buf;


    return 0;
}

