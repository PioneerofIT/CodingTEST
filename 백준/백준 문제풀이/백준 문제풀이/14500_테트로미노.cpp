#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int n, m;
int arrMap[501][501];
bool visited[501][501];
bool subVisited[501][501];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int dfsArr[4];
int numMax = INT_MIN;
void DFS(int L, int x, int y, int sum)
{
	if (L == 4)
	{
		numMax = max(numMax, sum);
		return;

	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			int nextX = x + dx[i];
			int nextY = y + dy[i];

			if (nextX < 1 || nextX > n || nextY <1 || nextY > m) continue;

			if (!subVisited[nextX][nextY])
			{
				subVisited[nextX][nextY] = true;
				DFS(L + 1, nextX, nextY, sum + arrMap[nextX][nextY]);
				subVisited[nextX][nextY] = false;
			}

		}
	}
}

void CheckT(int x, int y) // "っ" , "た", "で", "ぬ" 端滴
{
	int center = arrMap[x][y];

	for (int i = 0; i < 4; i++)
	{
		int temp = center;
		bool IsValid = true;
		for (int j = 0; j < 4; j++)
		{
			if (i == j) continue;

			int nextX = x + dx[j];
			int nextY = y + dy[j];

			if (nextX < 1 || nextX > n || nextY <1 || nextY > m)
			{
				IsValid = false;
				break;
			}
			
			temp += arrMap[nextX][nextY];

		}
		if (IsValid)
			numMax = max(numMax, temp);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> arrMap[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			memset(subVisited, false, sizeof(subVisited));
			subVisited[i][j] = true;
			DFS(1, i, j, arrMap[i][j]);
			
			CheckT(i, j);
		}
	}
	
	cout << numMax;
	return 0;
}