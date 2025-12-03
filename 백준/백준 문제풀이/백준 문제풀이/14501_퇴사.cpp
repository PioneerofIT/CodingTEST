#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct counselSchedule
{
	int T;
	int P;
	counselSchedule(int t, int p)
	{
		T = t;
		P = p;
	}

};

int n;
int visited[8];
vector< counselSchedule> vSchedule;
int maxVal = INT_MIN;

void DFS(int L, int sumVal)
{
	if (L == n+1)
	{
		maxVal = max(maxVal, sumVal);
		return;
	}

	if (L > n + 1)
		return;

	//선택하는 경우 건너 뛰는 경우?

	//case 1) 선택
	DFS(L + vSchedule[L].T , sumVal + vSchedule[L].P);
	//case 2) 건너뛰는 경우
	DFS(L + 1, sumVal);
		
	
}
int main()
{
	cin >> n;
	vSchedule.push_back(counselSchedule(0, 0)); // No idx 0

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		vSchedule.push_back(counselSchedule(a, b));
	}

	DFS(1, 0); // 1일차 스타트


	cout << maxVal;

	return 0;
}