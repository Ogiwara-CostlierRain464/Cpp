// BinaryFileRead.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <cstdint>

#define Uchar unsigned char
#define Ushort unsigned short
#define MAXMEMORY 10000

Uchar endian(Uchar val) {
	val = static_cast<Uchar>((val & 0x00FF) << 8 | (val & 0xFF00) >> 8);
	return val;
}

//GOMI
template<class T>
class  EndianConvert{
public:
	bool convert(T *val) {
		int i;
		char *temp;
		if ((temp = (char *) calloc(sizeof(T),sizeof(char))) == NULL) {
			printf("ERROR at EndianConvert.convert");
			return false;
		}

		for (i = 0; i < sizeof(T); i++) {
			temp[i] = ((char*) val)[i];
		}
		for (i = 1; i <= sizeof(T); i++) {
			((char *)val)[i - 1] = temp[sizeof(T) - i];
		}

		free(temp);
		return true;
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
		if (error = fopen_s(&fp,filepath,"rb") != 0) {
			printf("ERROR");
			exit(EXIT_FAILURE);
		}
		fread(data,sizeof(Uchar),MAXMEMORY,fp);
		current_pos = 0;
	}

	Uchar GetByte() {
		current_pos += 1;
		return data[current_pos -1];
	}

	Ushort GetShort() {
		CharAyToShort buff;
		for (int i = 0; i < 2;i++) {
			buff.cr[i] = GetByte();
			printf("Buffer<%d>: %02X", i,buff.cr[i]);
		}
		return endian(buff.st);
	}

private:
	unsigned int current_pos;
	Uchar data[MAXMEMORY];
};

int main()
{
	Tape tape("C:\\Users\\ogiwara\\Desktop\\level\\a.d");
	Uchar id = tape.GetByte();
	printf("ID[%02X]",id);
	Ushort length = tape.GetShort();
	printf("LENGTH[%04X]",length);

	char str[34];
	std::cin >> str;
	return EXIT_SUCCESS;
}

