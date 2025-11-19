#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int m, n, h; // 열 가로 높이
int tomato[101][101][101];
int dist[101][101][101];
int dx[6] = { 0, 1, 0, -1, 0, 0 };
int dy[6] = { 1, 0, -1, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

struct  tomatoNode
{
	int Z;
	int X;
	int Y;

	tomatoNode(int z, int x, int y)
	{
		Z = z;
		X = x;
		Y = y;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	queue<tomatoNode> Q;

	cin >> m >> n >> h; //열, 가로 , 높이

	for (int z = 1; z <= h; z++)
	{
		for (int i = 1; i <= n; i++)
		{   
			for (int j = 1; j <= m; j++)
			{  
				cin >> tomato[z][i][j];
				if (tomato[z][i][j] == 1)
					Q.push(tomatoNode(z, i, j));
			}
		}
	}

	while (!Q.empty())
	{
		tomatoNode node = Q.front(); Q.pop();
		int z = node.Z;
		int x = node.X;
		int y = node.Y;

		for (int i = 0; i < 6; i++)
		{
			int zz = z + dz[i];
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (tomato[zz][xx][yy] != 0) continue;

			if (zz < 1 || zz > h || xx < 1 || xx > n || yy < 1 || yy > m) continue;
			
			dist[zz][xx][yy] = dist[z][x][y] + 1;
			Q.push(tomatoNode(zz, xx, yy));
			tomato[zz][xx][yy] = 1;
			

		}
	}

	bool allRipe = true;
	int maxDay = 0;

	for (int z = 1; z <= h; z++) {
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <= m; y++) {
				if (tomato[z][x][y] == 0) {  // 아직 익지 않은 토마토
					allRipe = false;
				}
				maxDay = max(maxDay, dist[z][x][y]);
			}
		}
	}

	if (!allRipe) cout << -1;
	else cout << maxDay;


	return 0;
}