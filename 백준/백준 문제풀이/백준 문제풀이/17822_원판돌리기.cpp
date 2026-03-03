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

void DeleteCircle()
{
	queue<int> Q;
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++) 
		{
			// BFS 돌리면 될 듯?
		}
	}
}

void DecideCirCle(int x, int d, int k)
{
	vector<int> vecTargetCircle;
	vecTargetCircle.clear();

	//int arrTempCircleMap[51][51];
	//memset(arrTempCircleMap, 0, sizeof(arrTempCircleMap));


	for (int i = 1; i <= N; i++)
	{
		if (i % x == 0)
		{
			vecTargetCircle.push_back(i);
		}
	}

	for (int i = 0; i < vecTargetCircle.size(); i++)
	{
		int nCircleIdx = vecTargetCircle[i];

		for (int j = 0; j < k; k++)
		{
			RotateCircle(nCircleIdx, d);
		}

	}

	DeleteCircle();
}

void RotateCircle(int circleIdx, int dir)
{
	if (dir == 0) // 시계 방향
	{
		int temp = arrCircleMap[circleIdx][M];

		for (int i = M; i > 0; i--)
		{
			arrCircleMap[circleIdx][i] = arrCircleMap[circleIdx][i - 1];
		}
		arrCircleMap[circleIdx][0] = temp;
	}
	else if (dir == 1) // 반시계 방향
	{
		int temp = arrCircleMap[circleIdx][0];

		for (int i = 0; i < M; i++)
		{
			arrCircleMap[circleIdx][i] = arrCircleMap[circleIdx][i + 1];
		}
		arrCircleMap[circleIdx][M] = temp;

	}
}

int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> T;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arrCircleMap[i][j]; // row는 반지름 
		}
	}

	for (int i = 0; i < T; i++)
	{
		int x, d, k;

	
	}

	
	
	return 0;
}