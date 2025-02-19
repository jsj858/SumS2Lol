#include <iostream>

using namespace std;

// Template : ���� Ʋ
// => ������ ���� ���� ����� ����

// ���ø��Լ� : �Լ��� ���� Ʋ
template <typename T = int>
void PrintNum(T num)
{
	cout << num << endl;
}

// ���ø��Լ��� Ư��ȭ
template<>
void PrintNum(double num)
{
	cout << "Double �� �Լ� ����!!" << endl;
	cout << num << endl;
}


int main()
{
	int aInt = 1;
	PrintNum(aInt); // =>

	double aDouble = 1.1;
	PrintNum<double>(aDouble);

	return 0;
}