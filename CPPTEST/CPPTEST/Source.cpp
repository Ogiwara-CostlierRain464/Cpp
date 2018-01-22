template<class T>
T abs(T arg) {
	return (arg < 0) ? -arg : arg;
}

#include <iostream>
using namespace std;

class TestClass {
	public:
		TestClass() {
			//コンスト
		}

		~TestClass()
		{
			//destruct
		}

		int getsize() {
			return size;
		}

	private:
		int size;
};

void endr() {
	char aha[10];
	cin >> aha;
}

void main() {
	int n1, n2, n3;
	cin >> n1 >> n2;

	// 例外が起こるかもしれないブロック
	try {
		if (n2 == 0)
			throw n2;
		if (n1 == 0)
			throw "0をどんな数で割っても0に決まってるじゃん";
		if (n1 == n2)
			throw &n1;

		n3 = abs(n1) / n2;
		cout << "余算を実行しました" << endl;
		cout << n1 << " / " << n2 << " = " << n3 << endl;
	}
	catch (int arg) {
		// 例外が起きた場合に処理したいブロック
		cout << "余算エラー:" << arg << endl;
	}
	catch (char* arg) {
		// 例外が起きた場合に処理したいブロック
		cout << "余算エラー:" << arg << endl;
	}
	// 上記以外の例外
	catch (...) {
		cout << "int型、char*型以外の例外を受けとりました" << endl;
	}

	endr();
}