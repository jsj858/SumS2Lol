#include <iostream>

using namespace std;

// 로또번호 뽑기
// 1. 1 ~ 45의 숫자 중에서 중복없이 7개의 숫자를 뽑는다.
// 2. 이를 정렬한다.
// 3. 출력한다.

//            1      2
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Sort(int arr[], int size)
{
	// 구현
}

void PrintArr(int arr[], int size)
{
	// 구현
}

void Lotto()
{
	// 7개의 랜덤하고, 중복되지 않은 수
	// 구현

	// 정렬
	//Sort(arr, size);

	// 출력
	// PrintArr(arr,size);
}

int main()
{
	int aInt = 1;
	int bInt = 2;
	Swap(aInt, bInt);

	return 0;
}