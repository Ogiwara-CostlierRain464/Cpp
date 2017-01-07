// InLineAsm.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
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
	}//returnしてないじゃん!!!!!!
	end = clock();
	printf("%.8f秒かかりました\n",(double)(end-start)/CLOCKS_PER_SEC);
}
//EAXはreturn値格納…?
//ECXはループカウンタ
//EDI ESI アドレス番地を保存する iで終わっている
//[]で囲むと、データを参照->そのデータの番地に飛ぶ *p(ポインタの数値モード)
//AL EAX(32bit)の8bit版
//REP ecxの回数だけrepeatする(リピートフィックス)
//movsb esiの示す番地から1byte持って来て、ediの示す番地にコピー
//	->esiとediをそれぞれ+1 (ストリング)
//inc dec 第一引数のレジスタの値を++ , -- 速い!
//MMX技術 レジスタの効率的な利用 浮動小数点レジスタ(80bit)のうち64bit使用
//movq 64bit版mov 64bitのデータの移動に使用
//mm0 mm1 MMX用のレジスタ(64bit)
//paddd addの64bit版
//emms MMX後処理 mm0,1は本来は浮動小数点レジスタなので、戻してあげる

//cmp,jneはやらなくていいよね…

//EBXにはpopされたデータが入る?
//ESPには、スタックセクションの、次に取り出す要素の場所が保存してある<=変更する必要がある
//スタックセクションはレジスタではなく、メモリに存在。
//パラメータが少なくても、C等の高級言語ではメモリを使う手段しかない
//なので、アセンブラはレジスタを使うか、めもりを使うか選択できるので速い!

//call,retは割愛
/*

　　　　 EAX(32BIT)　　
	 ┌───────────┐
	 │　　　　　　AX(16BIT) │
	 　　　　　　┌─────┐
		   　　　│　　　　　│
	 ┌─────┬──┬──┐
	 │　　　　　│ AH │ AL │
	 └─────┴──┴──┘
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

