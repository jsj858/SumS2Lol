#include <iostream>

using namespace std;

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Sort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i] < arr[j])
			{
				Swap(arr[i], arr[j]);
			}
		}
	}
}

void PrintArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}

void Lotto()
{
	srand(time(NULL));

	int arr[7] = {};
	int count = 0;

	
	while (arr[count] == 0)
	{
		int temp = rand() % 45 + 1;
		bool IsDuplicated = false;

		for (int i = 0; i < 7; i++)
		{
			if (arr[i] == temp)
			{
				IsDuplicated = true;
				break;
			}
		}

		if (!IsDuplicated)
			arr[count++] = temp;
	}
	
	Sort(arr, 7);

	PrintArr(arr, 7);
}

int main()
{

	Lotto();

	return 0;
}