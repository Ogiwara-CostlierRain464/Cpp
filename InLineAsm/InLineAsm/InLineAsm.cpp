// InLineAsm.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	char foo = 0x41;
	__asm {
		mov eax, foo//�ړI��?
		
	}

	

	char buf[23];
	cin >> buf;
	return 0;
}

