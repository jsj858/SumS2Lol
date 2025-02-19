#include <iostream>
#include <vector>

using namespace std;

int N;
int M;
vector<int> v;
vector<int> answer;


void Input()
{
	cin >> N;
	cin >> M;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		
		v.push_back(temp);
	}

	for (int i = 0; i < M; i++)
	{
		int n1;
		int n2;
		int temp = 0;
		cin >> n1;
		cin >> n2;

		for (int i = 0; i < n2 - n1; i++)
		{
			temp += v[n1 - 1 + i];
		}
		answer.push_back(temp);
	}

	for (int n : answer)
	{
		cout << n << endl;
	}
}

int cache[301];

int DP(int n)
{
	// 기저사항
	if (n < 0)
		return 0;

	// 메모이제이션
	int& ref = cache[n];
	if (ref != -1)
		return ref;

	// 구하기
	// 한칸
	if (n > 0)
		ref = v[n] + v[n - 1] + DP(n - 3);

	// 두칸 뛰기
	ref = max(ref, v[n]) + DP(n - 2);

	return ref;
}

int main()
{
	int n;
	int m;
	vector<int> vN;
	vector<int> addV;

	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		if (i == 0)
		{
			addV.push_back(temp);
			vN.push_back(temp);
		}
		else
		{
			addV.push_back(temp + addV[i - 1]);
			vN.push_back(temp);
		}
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a;
		cin >> b;

		if (a == b)
		{
			cout << vN[a - 1] << endl;
			continue;
		}
		if (a == 1)
		{
			cout << addV[b - 1] << endl;
			continue;
		}
		cout << addV[b - 1] - addV[a - 2] << endl;
	}

	/*5 3
		5 4 3 2 1
		1 3
		2 4
		5 5*/

	//Input();

	/*for (int i = 0; i < 301; i++)
	{
		cache[i] = -1;
	}

	cout << DP(v.size() - 1) << endl;*/

	return 0;
}