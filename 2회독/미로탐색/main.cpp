#include<iostream>
#include <queue>

using namespace std;
int n, m; // n(За), m(ї­)
int dist[101][101];
int map[101][101];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

struct Node
{
	int X;
	int Y;

	Node(int x, int y)
	{
		this->X = x;
		this->Y = y;
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
	        map[i][j] = line[j - 1] - '0';
	    }
	}

	Q.push(Node(1, 1));

	while (!Q.empty())
	{
		Node node = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int xx = node.X + dx[i];
			int yy = node.Y + dy[i];

			if (xx == n && yy == m)
			{
				cout << dist[node.X][node.Y] + 2;
    			return 0;
			}

			if (xx > 0 && xx <= n && yy > 0 && yy <= m)
			{
				if (map[xx][yy] == 1 && dist[xx][yy] == 0) //
				{
					Q.push(Node(xx, yy));
					dist[xx][yy] = dist[node.X][node.Y] + 1;
				}
			}
		}
	}

	cout << dist[n][m] + 2;
	
	return 0;

}
