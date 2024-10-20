#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n; // ������ ���� 
int c; // ��ġ �ؾ��ϴ� ���� ��
vector<int> d(n); // distance

int GetAvailHorse(int nMid) // parameter : mid
{
	int cnt = 1;
	int pos = d[0];

	for (int i = 2; i < n-1; i++)
	{
		if (d[i] - pos >= nMid)
		{
			pos = d[i];
			cnt++;
		}
	}

	return cnt;
}

int main(int argc, char** argv)
{

	cin >> n >> c;
	d.resize(n); // n �Է� ���� �� ���� ũ�� ����

	for (int i = 0; i < n; i++)
	{
		cin >> d[i];
	}
	sort(d.begin(), d.end());

	int rt, lt, mid;

	lt = d[0];
	rt = d[n - 1];

	int res;


	while (lt <= rt)
	{
		mid = (lt + rt) / 2;


		if (GetAvailHorse(mid) >= c) // ������ �� �ٿ�����? 
		{
			res = mid;
			lt = mid + 1;
		}
		else
		{
			rt = mid - 1;
		}
	}

	cout << res;
	return 0;
}
