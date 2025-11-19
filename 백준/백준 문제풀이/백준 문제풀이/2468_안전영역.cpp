#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

int n;
int map[101][101];
bool visited[101][101];
bool IsSafetyArea[101][101];
int maxHeight = INT_MIN;
int maxArea = INT_MIN;
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
	cin.tie(0);
	queue<Node> Q;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
			maxHeight = max(maxHeight, map[i][j]);
		}
	}

	for (int k = 0; k <= maxHeight; k++)
	{
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (map[i][j] <= k)
				{
					IsSafetyArea[i][j] = false; 
				}
				else
				{
					IsSafetyArea[i][j] = true;
				}
			}
		}

		for (int a = 1; a <= n; a++)
		{
			for (int b = 1; b <= n; b++)
			{
				if (IsSafetyArea[a][b] && !visited[a][b])
				{	
					cnt++;
					visited[a][b] = true;
					Q.push(Node(a, b));

					while (!Q.empty())
					{
						Node now = Q.front(); Q.pop();

						int x = now.X;
						int y = now.Y;

						for (int z = 0; z < 4; z++)
						{
							int xx = x + dx[z];
							int yy = y + dy[z];

							if (xx >= 1 && xx <= n && yy >= 1 && yy <= n && !visited[xx][yy] && IsSafetyArea[xx][yy] == true)
							{
								visited[xx][yy] = true;
								Q.push(Node(xx, yy));
							}
						}
					}
				}
			}
		}
		maxArea = max(maxArea, cnt);
		for (int c = 1; c <= n; c++)
		{
			for (int d = 1; d <= n; d++)
			{
				visited[c][d] = false;
			}
		}

	}

	cout << maxArea;
	return 0;

}