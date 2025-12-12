#include <iostream>
#include <queue>
using namespace std;

struct nodeState
{
	int Rx, Ry;
	int Bx, By;
	int Depth;

	nodeState(int rx, int ry, int bx, int by, int depth)
	{
		Rx = rx; Ry = ry;
		Bx = bx; By = by;
		Depth = depth;
	}
};

int map[11][11];
bool visited[11][11][11][11];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int n, m;
int endX, endY;
int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	int Rx, Ry, Bx, By;
	queue<nodeState> Q;

	string line;
	for (int i = 1; i <= n; i++)
	{
		cin >> line;
		for (int j = 1; j <= m; j++)
		{
			if (line[j - 1] == '#') map[i][j] = 1;
			else if (line[j - 1] == '.') map[i][j] = 0;
			else if (line[j - 1] == 'B')
			{
				Bx = i;
				By = j;
				map[i][j] = 0;
			}
			else if (line[j - 1] == 'R')
			{
				Rx = i;
				Ry = j;
				map[i][j] = 0;
			}
			else if (line[j - 1] == 'O')
			{
				endX = i;
				endY = j;
				map[i][j] = -1;
			}
			
		}
	}
	visited[Rx][Ry][Bx][By] = true;
	Q.push(nodeState(Rx, Ry, Bx, By, 0));

	while (!Q.empty())
	{
		nodeState now = Q.front(); Q.pop();

		if (now.Depth >= 10)
		{
			continue;
		}


		for (int i = 0; i < 4; i++) // 한 쪽으로만 굴리기
		{
		
			bool isRedHole = false;
			bool isBlueHole = false;
			int nowRx = now.Rx;
			int nowRy = now.Ry;

			while (true) // Red roll
			{
				int nRx = nowRx + dx[i];
				int nRy = nowRy + dy[i];

				if (nRx == endX && nRy == endY)
				{
					isRedHole = true;
					nowRx = nRx;
					nowRy = nRy;
					break;
				}

				if (nRx >= 1 && nRx <= n && nRy>=1 &&nRy <= m && map[nRx][nRy] == 1)
				{
					break;
				}
				nowRx = nRx;
				nowRy = nRy;
			}

			int nowBx = now.Bx;
			int nowBy = now.By;
			while (true) // Blue Roll
			{
				int nBx = nowBx + dx[i];
				int nBy = nowBy + dy[i];

				if (nBx == endX && nBy == endY)
				{
					isBlueHole = true;
					nowBx = nBx;
					nowBy = nBy;
					break;
				}

				if (nBx >= 1 && nBx <= n && nBy >= 1 && nBy <= m && map[nBx][nBy] == 1)
				{
					break;
				}
				nowBx = nBx;
				nowBy = nBy;
			}
			if (isBlueHole)
			{
				continue;
			}
			if (isRedHole && !isBlueHole)
			{
				cout << now.Depth + 1;
				return 0;
			}

			if (isRedHole && isBlueHole)
			{
				continue;
			}

			if (nowRx == nowBx && nowRy == nowBy)
			{
				int redDistance = abs(nowRx - now.Rx) + abs(nowRy - now.Ry);
				int blueDistance =  abs(nowBx - now.Bx) + abs(nowBy - now.By);

				if (redDistance > blueDistance)
				{
					nowRx -= dx[i];
					nowRy -= dy[i];
				}
				else
				{
					nowBx -= dx[i];
					nowBy -= dy[i];
				}
			}

			if (!visited[nowRx][nowRy][nowBx][nowBy])
			{
				visited[nowRx][nowRy][nowBx][nowBy] = true;
				Q.push(nodeState(nowRx, nowRy, nowBx, nowBy, now.Depth + 1));
			}
		}
	}
	
	cout << -1;
	return 0;
}