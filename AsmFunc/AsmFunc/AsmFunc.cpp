// BinaryFileRead.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <cstdint>

#define Uchar unsigned char
#define Ushort unsigned short
#define Uint unsigned int
#define MAXMEMORY 10000

class Endian {
public:
	static bool isLittle() {
		int x = 1;
		if (*(char *)&x) {
			return true;
		}
		else {
			return false;
		}
	}

	static Ushort convert(Ushort i) {
		return i << 8 | i >> 8;
	}

	static Uint convert(Uint i) {
		return i << 24 | i << 8 & 0x00ff0000 | i >> 8 & 0x0000ff00 | i >> 24 & 0x000000ff;
	}
};

class Tape {
public:
	union CharAyToShort
	{
		Uchar cr[2];
		Ushort st;
	};


	Tape(char* filepath) {
		FILE *fp;
		errno_t error;
		if (error = fopen_s(&fp, filepath, "rb") != 0) {
			printf("ERROR");
			exit(EXIT_FAILURE);
		}
		fread(data, sizeof(Uchar), MAXMEMORY, fp);
		current_pos = 0;
	}

	Uchar GetByte() {
		current_pos += 1;
		return data[current_pos - 1];
	}

	Ushort GetShort() {
		CharAyToShort buff;
		for (int i = 0; i < 2; i++) {
			buff.cr[i] = GetByte();
			printf("Buffer<%d>: %02X", i, buff.cr[i]);
		}
		return buff.st;
	}

	char* GetString(Uchar length) {
		return GetAs(length);
	}

	char* GetAs(Uchar times) {
		char* str;
		for (Uchar i = 0; i < times; i++) {
			char* a = str + i;
			*a = (char)GetByte();
		}
		return str;
	}

private:
	unsigned int current_pos;
	Uchar data[MAXMEMORY];
};

class AsmTape {
public:
	static int Loadfile(char* filepath) {
		_asm {
			mov si, filepath
			mov ax, 0x3D00
			mov dx, si
			int 0x21
			ja BAD
			jb OK
		OK :
			mov eax, 1
				jmp FIN
		BAD :
			mov eax, 0
				jmp FIN
		FIN :
		}
	}
};

int main()
{
	/*Tape tape("C:\\Users\\ogiwara\\Desktop\\level\\a.d");
	Uchar id = tape.GetByte();
	printf("ID[%02X]", id);
	Ushort length = tape.GetShort();
	printf("LENGTH[%04X]", Endian::isLittle() ? Endian::convert(length) : length);
	char* Key = tape.GetString(length);
	printf("KEY[%c]", Key);

	char str[34];
	std::cin >> str;
	return EXIT_SUCCESS;*/
	int result = AsmTape::Loadfile("C:\\Users\\ogiwara\\Desktop\\level\\a.d");
	printf("Result is %d",result);
	char str[34];
	std::cin >> str;
	return result;
}

