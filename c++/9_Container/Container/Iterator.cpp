#include <iostream>
#include <vector>
#include <list>

using namespace std;

#include "List.h"
#include "Vector.h"

// iterator : �ݺ��� (��ȸ��)

int main()
{
	Vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	// vector�� �������ٿ����ڷ� ��ȸ�� �����ϴ�. <-> list�� ��ȸ�Ұ���
	/*for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}*/

	// vector�� iter�� ��ȸ�ϴ� ���
	Vector<int>::Iterator iter;
	iter = v.begin();
	for (iter; iter != v.end(); iter++)
	{
		cout << *iter << endl;
	}

	cout << "-----------" << endl;
	List<int> mylist;
	mylist.push_back(5);
	mylist.push_back(6);
	mylist.push_back(7);
	mylist.push_back(8);

	List<int>::Iterator myListIter = mylist.begin();

	for (myListIter; myListIter != mylist.end(); myListIter++)
	{
		cout << *myListIter << endl;
	}

	return 0;
}