#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int N, M, T;
int dr[4] = { 0, -1, 0, 1 };
int dc[4] = { 1, 0, -1, 0 };
int arrCircleMap[51][51]; // 1-based
int arrRotInfo[50][3]; // x, d, k

int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> T;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arrCircleMap[i][j];
		}
	}

	for (int i = 0; i < T; i++)
	{
		cin >> arrRotInfo[i][0] >> arrRotInfo[i][1] >> arrRotInfo[i][2]; // x, d, k
	}

	
	
	return 0;
}