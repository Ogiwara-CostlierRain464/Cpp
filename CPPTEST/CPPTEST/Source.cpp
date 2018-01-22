template<class T>
T abs(T arg) {
	return (arg < 0) ? -arg : arg;
}

#include <iostream>
using namespace std;

class TestClass {
	public:
		TestClass() {
			//�R���X�g
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

	// ��O���N���邩������Ȃ��u���b�N
	try {
		if (n2 == 0)
			throw n2;
		if (n1 == 0)
			throw "0���ǂ�Ȑ��Ŋ����Ă�0�Ɍ��܂��Ă邶���";
		if (n1 == n2)
			throw &n1;

		n3 = abs(n1) / n2;
		cout << "�]�Z�����s���܂���" << endl;
		cout << n1 << " / " << n2 << " = " << n3 << endl;
	}
	catch (int arg) {
		// ��O���N�����ꍇ�ɏ����������u���b�N
		cout << "�]�Z�G���[:" << arg << endl;
	}
	catch (char* arg) {
		// ��O���N�����ꍇ�ɏ����������u���b�N
		cout << "�]�Z�G���[:" << arg << endl;
	}
	// ��L�ȊO�̗�O
	catch (...) {
		cout << "int�^�Achar*�^�ȊO�̗�O���󂯂Ƃ�܂���" << endl;
	}

	endr();
}