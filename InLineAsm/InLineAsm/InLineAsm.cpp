// InLineAsm.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <time.h>

using namespace std;

int sub(char* a,char* b) {
	printf("sub routine called\n");
	clock_t start, end;
	start = clock();
	_asm {
		mov edi,a
		mov esi,b
		mov ecx,8
	LOOP1:
		mov al,[edi]
		mov bl,[esi]
		add al,bl
		mov [edi],al
		inc edi
		inc esi
		dec ecx
		cmp ecx,0
		jne LOOP1
	}//return���ĂȂ������!!!!!!
	end = clock();
	printf("%.8f�b������܂���\n",(double)(end-start)/CLOCKS_PER_SEC);
}
//EAX��return�l�i�[�c?
//ECX�̓��[�v�J�E���^
//EDI ESI �A�h���X�Ԓn��ۑ����� i�ŏI����Ă���
//[]�ň͂ނƁA�f�[�^���Q��->���̃f�[�^�̔Ԓn�ɔ�� *p(�|�C���^�̐��l���[�h)
//AL EAX(32bit)��8bit��
//REP ecx�̉񐔂���repeat����(���s�[�g�t�B�b�N�X)
//movsb esi�̎����Ԓn����1byte�����ė��āAedi�̎����Ԓn�ɃR�s�[
//	->esi��edi�����ꂼ��+1 (�X�g�����O)
//inc dec �������̃��W�X�^�̒l��++ , -- ����!
//MMX�Z�p ���W�X�^�̌����I�ȗ��p ���������_���W�X�^(80bit)�̂���64bit�g�p
//movq 64bit��mov 64bit�̃f�[�^�̈ړ��Ɏg�p
//mm0 mm1 MMX�p�̃��W�X�^(64bit)
//paddd add��64bit��
//emms MMX�㏈�� mm0,1�͖{���͕��������_���W�X�^�Ȃ̂ŁA�߂��Ă�����

//cmp,jne�͂��Ȃ��Ă�����ˁc

//EBX�ɂ�pop���ꂽ�f�[�^������?
//ESP�ɂ́A�X�^�b�N�Z�N�V�����́A���Ɏ��o���v�f�̏ꏊ���ۑ����Ă���<=�ύX����K�v������
//�X�^�b�N�Z�N�V�����̓��W�X�^�ł͂Ȃ��A�������ɑ��݁B
//�p�����[�^�����Ȃ��Ă��AC���̍�������ł̓��������g����i�����Ȃ�
//�Ȃ̂ŁA�A�Z���u���̓��W�X�^���g�����A�߂�����g�����I���ł���̂ő���!

//call,ret�͊���
/*

�@�@�@�@ EAX(32BIT)�@�@
	 ��������������������������
	 ���@�@�@�@�@�@AX(16BIT) ��
	 �@�@�@�@�@�@��������������
		   �@�@�@���@�@�@�@�@��
	 ��������������������������
	 ���@�@�@�@�@�� AH �� AL ��
	 ��������������������������
*/


int main()
{
	char a[8] = {0,1,2,3,4,5,6,7};
	char b[8] = {10,11,12,13,14,15,16,17};
	for (int i = 0; i < 8;i++) {
		printf("a[%d]:%d b[%d]:%d\n",i,a[i],i,b[i]);
	}
	sub(&a[0],&b[0]);
	for (int i = 0; i < 8; i++) {
		printf("a[%d]:%d b[%d]:%d\n",i, a[i],i, b[i]);
	}
	char h[9];
	cin >> h;
	return 0;
}

