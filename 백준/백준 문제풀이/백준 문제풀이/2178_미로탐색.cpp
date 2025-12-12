#include <iostream>
#include <queue>
using namespace std;

int arrMap[101][101];
bool visited[101][101];
int n, m;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int dist[101][101];
struct Node
{
	int X;
	int Y;
	Node(int x, int y)
	{
		X = x; Y = y;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	queue<Node> Q;

	cin >> n >> m;

	string line;
	for (int i = 1; i <= n; i++)
	{
		cin >> line;
		for (int j = 1; j <= m; j++)
		{
			arrMap[i][j] = line[j - 1]- '0';
		}
	}

	dist[1][1] = 1;
	visited[1][1] = true;
	Q.push(Node(1, 1));

	while (!Q.empty())
	{
		Node now = Q.front(); Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int xx = now.X + dx[i];
			int yy = now.Y + dy[i];

			if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && arrMap[xx][yy] == 1 && !visited[xx][yy] )
			{
				visited[xx][yy] = true;
				dist[xx][yy] = dist[now.X][now.Y] + 1;
				Q.push(Node(xx, yy));
			}
		}
	}

	cout << dist[n][m];
}