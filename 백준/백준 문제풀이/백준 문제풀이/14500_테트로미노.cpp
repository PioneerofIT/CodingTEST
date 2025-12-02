#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

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
		if (numMax < sum)
		{
			numMax = sum;
			return;
		}

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
			if (!visited[i][j])
			{
				visited[i][j] = true;	
				DFS(1, i, j, arrMap[i][j]);
			}
		}
	}
	
	cout << numMax;
	return 0;
}