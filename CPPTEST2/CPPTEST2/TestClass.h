#pragma once//コンパイラによってファイルが 1 回だけ取り込まれるように
class TestClass {
public:
	TestClass(int n);    // コンストラクタ
	~TestClass();        // デストラクタ
	void   print();

protected:
	int   size;
};