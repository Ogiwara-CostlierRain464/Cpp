#include "DxLib.h"
#include <math.h>
#define PI 3.141592654f

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);
	SetUseZBuffer3D(true);
	SetWriteZBuffer3D(true);

	int Handler = LoadGraph("‰æ‘œ/’e00.png");

	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {
		DrawBillboard3D(VGet(320.0f, 240.0f, 100.0f), 0.5f, 0.5f, 120.0f, 0.0f, Handler, TRUE);
	}

	DxLib_End();
	return 0; 
}