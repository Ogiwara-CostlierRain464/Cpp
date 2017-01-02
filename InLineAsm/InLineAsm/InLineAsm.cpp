// InLineAsm.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	char foo = 0x41;
	__asm {
		mov eax, foo//目的は?
		
	}

	

	char buf[23];
	cin >> buf;
	return 0;
}

