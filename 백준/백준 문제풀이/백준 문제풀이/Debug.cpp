#include <iostream>
#include <queue>
using namespace std;

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

int n, m;
int nMap[101][101];
int dist[101][101];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };


int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	queue<Node> Q;

	cin >> n >> m;

	string line;
	for (int i = 1; i <= n; i++)
	{
		cin >> line;
		for (int j = 1; j <= m; j++)
		{
			nMap[i][j] = line[j - 1] - '0';

		}
	}

	nMap[1][1] = 0;
	Q.push(Node(1, 1));

	while (!Q.empty())
	{
		Node nowNode = Q.front(); Q.pop();

		int x = nowNode.X;
		int y = nowNode.Y;

		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx >= 1 && xx <= 100 && yy >= 1 && yy <= 100 && nMap[xx][yy] == 1)
			{
				nMap[xx][yy] = 0;
				dist[xx][yy] = dist[x][y] + 1;
			}
		}
	}
	cout << dist[n][m];


	return 0;
}