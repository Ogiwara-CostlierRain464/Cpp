#include <windows.h>

DWORD WINAPI ThreadFunc(LPVOID vdParam) {
	HDC hdc;
	unsigned int iCount = 0;
	TCHAR strCount[128];

	while (TRUE) {
		hdc = GetDC((HWND)vdParam);

		InvalidateRect((HWND)vdParam, NULL, TRUE);
		wsprintf(strCount, TEXT("Count = %d"), iCount);
		TextOut(hdc, 10, 10, strCount, lstrlen(strCount));

		ReleaseDC((HWND)vdParam, hdc);
		iCount = iCount == 0xFFFFFFFF ? 0 : iCount + 1;
	}
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	DWORD dwID;

	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_CREATE:
		CreateThread(NULL, 0, ThreadFunc, (LPVOID)hWnd, 0, &dwID);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wp, lp);
}

int WINAPI WInMain(HINSTANCE hinstance,HINSTANCE hprevinstance,PSTR lpcmdline,int ncmdshow) {
	HWND hwnd;
	MSG msg;
	WNDCLASS winc;

	winc.style = CS_HREDRAW | CS_VREDRAW;
	winc.lpfnWndProc = WndProc;
	winc.cbClsExtra = winc.cbWndExtra = 0;
	winc.hInstance = hinstance;
	winc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winc.hCursor = LoadCursor(NULL, IDC_ARROW);
	winc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	winc.lpszMenuName = NULL;
	winc.lpszClassName = TEXT("KITTY");

	if (!RegisterClass(&winc)) return 1;

	hwnd = CreateWindow(
		TEXT("KITTY"), TEXT("Kitty on your lap"),
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hinstance, NULL
	);

	if (hwnd == NULL) return 1;

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}