#include <iostream>

using namespace std;

int dx[4] = { -1, 0, 1, 0 }; 
int dy[4] = { 0, 1, 0, -1 }; // 방향 인덱스 그대로 넣어서 판단해도 된다.
int cleanMap[50][50];
bool IsClean[50][50];
int cleanCnt = 0;

struct cleanRobot
{
	int x;
	int y;
	int d; // 방향
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cleanRobot cb;

	int n, m;
	cin >> n >> m;
	cin >> cb.x >> cb.y >> cb.d;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> cleanMap[i][j];
		}
	}

	while (true)
	{
		if (!IsClean[cb.x][cb.y] && cleanMap[cb.x][cb.y] != 1)
		{
			IsClean[cb.x][cb.y] = true;
			cleanCnt++;
		}

		bool IsAllClean = true;

		for (int i = 0; i < 4; i++)
		{
			int xx = cb.x + dx[i];
			int yy = cb.y + dy[i];

			if (xx >= 0 && xx <= n && yy >= 0 && yy <= m &&  !IsClean[xx][yy]  && cleanMap[xx][yy] == 0)
			{
				IsAllClean = false;
				break;
			}
		}

		if (IsAllClean)
		{
			int xx = 0, yy = 0;
			switch (cb.d)
			{
			case 0:
				xx = cb.x + dx[2];
				yy = cb.y + dy[2];
			break;
			case 1:
				xx = cb.x + dx[3];
				yy = cb.y + dy[3];
				break;
			case 2:
				xx = cb.x + dx[0];
				yy = cb.y + dy[0];
				break;
			case 3:
				xx = cb.x + dx[1];
				yy = cb.y + dy[1];
				break;
			}
			if (xx >= 0 && xx <= n && yy >= 0 && yy <= m && cleanMap[xx][yy] != 1)
			{
				cb.x = xx;
				cb.y = yy;
				continue;
			}
			else
			{
				break;
			}
		}
		else
		{
			int xx, yy = 0;
			switch (cb.d)
			{
			case 0:
				cb.d = 3;
				break;
			case 1:
				cb.d = 0;
				break;
			case 2:
				cb.d = 1;
				break;
			case 3:
				cb.d = 2;
				break;
			}
			xx = cb.x + dx[cb.d];
			yy = cb.y + dy[cb.d];

			if (!IsClean[xx][yy] && cleanMap[xx][yy] == 0)
			{
				cb.x = xx;
				cb.y = yy;
			}
			continue;
		}
	}
	cout << cleanCnt;
	return 0;
}