#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n; // 마구간 갯수 
int c; // 배치 해야하는 말의 수
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
	d.resize(n); // n 입력 받은 후 벡터 크기 설정

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


		if (GetAvailHorse(mid) >= c) // 범위를 더 줄여볼까? 
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
