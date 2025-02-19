#include <iostream>

using namespace std;

// Template : 주조 틀
// => 뭔가를 쉽게 찍어내서 만들기 위한

// 템플릿함수 : 함수를 찍어내는 틀
template <typename T = int>
void PrintNum(T num)
{
	cout << num << endl;
}

// 템플릿함수의 특수화
template<>
void PrintNum(double num)
{
	cout << "Double 형 함수 생성!!" << endl;
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