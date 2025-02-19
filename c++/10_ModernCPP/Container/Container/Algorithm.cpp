#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool Find_if(int element)
{
	if (element > 25)
		return true;
	return false;
}

int main()
{
	vector<int> v = { 31, 23, 3, 2, 1, 3, 12, 15, 19 };

	// 1. v���� 23�� �ִ� ������ �ڸ�(index, iter)�� ã���ּ���.
	vector<int>::iterator iter = std::find(v.begin(), v.end(), 23);
	if (iter != v.end()) // ã�Ҵ�.
	{
		cout << *iter << endl;
	}
	cout << "--------------------------------------" << endl;
	// 2. v���� 25���� ū ���� �ִٸ� �� �ڸ��� ã���ּ���.
	iter = std::find_if(v.begin(), v.end(), &Find_if);

	struct Find_If_Functor
	{
		bool operator()(int element)
		{
			if (element > compareNum)
				return true;
			return false;
		}

		int compareNum;
	};
	Find_If_Functor functor1;
	functor1.compareNum = 25;
	iter = std::find_if(v.begin(), v.end(), functor1);

	functor1.compareNum = 27;
	iter = std::find_if(v.begin(), v.end(), functor1);

	cout << *iter << endl;
	cout << "--------------------------------------" << endl;
	// 3. v���� 3�� ������ �����
	cout << std::count(v.begin(), v.end(), 3) << endl;
	cout << "--------------------------------------" << endl;

	// 4. v���� 10���� ū ���� �����
	cout << std::count_if(v.begin(), v.end(), [](int count) {return count > 10; }) << endl;
	cout << "--------------------------------------" << endl;
	// 5. v���� ��� ���� 50���� ������
	cout << std::all_of(v.begin(), v.end(), [](int x) {return x < 50; }) << endl;
	cout << "--------------------------------------" << endl;
	// 6. v���� �ϳ��� 20���� ũ�� 30���� ���� ���� �ִ���
	cout << std::any_of(v.begin(), v.end(), [](int x) {return x > 20 && x < 30; }) << endl;
	cout << "--------------------------------------" << endl;
	// 7. v�� �迭�� ���ٷ� ������ּ���.
	std::reverse(v.begin(), v.end());
	for (int i : v)
	{
		cout << i << "\t";
	}
	cout << endl;
	cout << "--------------------------------------" << endl;
	// 8. �� v�� ���ҿ� 3�� �����ּ���.
	std::for_each(v.begin(), v.end(), [](int& x) {return x *= 3; });
	for (int& i : v)
	{
		cout << i << "\t";
	}
	cout << endl;
	cout << "--------------------------------------" << endl;
	// 9. v�� �������ּ���.
	std::sort(v.begin(), v.end());
	for (int i : v)
	{
		cout << i << "\t";
	}
	cout << endl;
	cout << "--------------------------------------" << endl;
	// 10. v���� �ߺ��� ���Ұ� �ִٸ� �������ּ���.
	v.erase(std::unique(v.begin(), v.end()),v.end());
	//std::unique(v.begin(), v.end()), v.end();
	for (int i : v)
	{
		cout << i << "\t";
	}
	cout << endl;
	cout << "--------------------------------------" << endl;
	// 11. v���� 45�� ���Ұ� �ִٸ� ����
	v.erase(std::remove(v.begin(), v.end(), 45), v.end());
	for (int i : v)
	{
		cout << i << "\t";
	}
	cout << endl;
	cout << "--------------------------------------" << endl;
	// 12. v���� 20���� ���� ���ҵ� ����
	v.erase(std::remove_if(v.begin(), v.end(), [](int x) {return x < 20; }), v.end());
	for (int i : v)
	{
		cout << i << "\t";
	}
	cout << endl;
	cout << "--------------------------------------" << endl;

	// 13. 57�� iter�� for�� ���鼭 �����
	for (iter = v.begin(); iter != v.end(); iter++)
	{
		if (*iter == 57)
		{
			//v.erase(iter--);
			iter = v.erase(iter);
		}
	}

	for (int i : v)
	{
		cout << i << "\t";
	}
	cout << endl;
	cout << "--------------------------------------" << endl;
	return 0;
}