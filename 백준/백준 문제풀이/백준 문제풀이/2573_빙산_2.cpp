#include <iostream>
#include <queue>
using namespace std;

int arrIceMap[301][301];
bool visited[301][301];
int melt[301][301];
int n, m;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

struct Node
{
	int X;
	int Y;
	Node(int x, int y)
	{
		X = x;
		Y = y;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	queue<Node> Q;
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> arrIceMap[i][j];
		}
	}

	int year = 0;
	while (true)
	{
		year++;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				int cnt = 0;
				visited[i][j] = false;
				if (arrIceMap[i][j] != 0)
				{
					for (int z = 0; z < 4; z++)
					{
						int xx = i + dx[z];
						int yy = j + dy[z];

						if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && arrIceMap[xx][yy] == 0)
						{
							cnt++;
						}
					}
				}
				melt[i][j] = cnt;
				cnt = 0;
			}
		}

		for (int a = 1; a <= n; a++)
		{
			for (int b = 1; b <= m; b++)
			{
				if (melt[a][b] != 0)
				{
					arrIceMap[a][b] -= melt[a][b];
					if (arrIceMap[a][b] <= 0) arrIceMap[a][b] = 0;
					melt[a][b] = 0;

				}
			}
		}

		int areaCnt = 0;
		for (int x = 1; x <= n; x++)
		{
			for (int y = 1; y <= m; y++)
			{
				
				if (arrIceMap[x][y] != 0 && !visited[x][y] )
				{
					visited[x][y] = true;
					Q.push(Node(x, y));

					while (!Q.empty())
					{
						Node now = Q.front(); Q.pop();

						for (int z = 0; z < 4; z++)
						{
							int xx = now.X + dx[z];
							int yy = now.Y + dy[z];

							if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && arrIceMap[xx][yy] != 0 && !visited[xx][yy])
							{
								visited[xx][yy] = true;
								Q.push(Node(xx, yy));
							}
						}
					}
					areaCnt++;
				}
			}
		}
		if ( areaCnt >= 2)
		{
			cout << year;
			return 0;
		}

		bool isAllmelt = true;
		for (int a = 1; a <= n; a++)
		{
			for (int b = 1; b <= m; b++)
			{
				if (arrIceMap[a][b] != 0)
				{
					isAllmelt = false;

				}
			}
		}
		if (isAllmelt)
		{
			cout << 0;
			return 0;
		}
	}

	return 0;
}