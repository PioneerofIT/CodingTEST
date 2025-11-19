#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
#include <cstring>
using namespace std;

/* CheckPoint
빙산을 동시에 녹여야 한다 → melt 배열로 한 번에 적용해야 함

BFS에서 바다까지 방문하는 버그

경계 조건(0~n) → 1~n으로 수정 필요

visited를 매년 초기화해야 함

melt 배열도 매년 초기화 필요

덩어리 조건은 ==2가 아니라 >=2

전부 녹은 경우(덩어리 0개) → 0 출력*/

int n, m;
int seaMap[301][301];
int melt[301][301];
bool visited[301][301];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int year = 0;
int seaArea = 0;

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
			cin >> seaMap[i][j];
		}
	}

	while (true)
	{
		year++;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				int cnt = 0;
				visited[i][j] = false;
				
				if (seaMap[i][j] > 0)
				{
					for (int z = 0; z < 4; z++)
					{
						int xx = i + dx[z];
						int yy = j + dy[z];

						if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && seaMap[xx][yy] == 0)
						{
							//seaMap[i][j]--; 동시성 위배
							cnt++;
						}
					}
				}
				melt[i][j] = cnt;

			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				seaMap[i][j] -= melt[i][j];
				if (seaMap[i][j] < 0)
				{
					seaMap[i][j] = 0;
				}
					
			}
		}
		memset(visited, false, sizeof(visited));
		seaArea = 0;
		for (int a = 1; a <= n; a++)
		{
			for (int b = 1; b <= m; b++)
			{
				if (seaMap[a][b] != 0 && !visited[a][b])
				{
					seaArea++;
					visited[a][b] = true;
					Q.push(Node(a, b));

					while (!Q.empty())
					{
						Node now = Q.front(); Q.pop();

						for (int c = 0; c < 4; c++)
						{
							int xx = now.X + dx[c];
							int yy = now.Y + dy[c];

							if( xx >= 1 && xx <= n && yy >= 1 && yy <= m && !visited[xx][yy] && seaMap[xx][yy] > 0)
							{
								visited[xx][yy] = true;
								Q.push(Node(xx, yy));
							}
						}
					}
;				}
			}
		}
		if (seaArea >= 2)
		{
			cout << year;
			break;
		}
		if (seaArea == 0)
		{
			cout << 0;
			break;
		}
	}

	return 0;
}