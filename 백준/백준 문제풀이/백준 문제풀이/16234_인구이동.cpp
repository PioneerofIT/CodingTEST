#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int dr[4] = { 0, 1, 0, -1  };
int dc[4] = { 1, 0, -1, 0 };
int arrMap[50][50];
bool visited[50][50];

int n, l, r;

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
	cin.tie(nullptr);

	cin >> n >> l >> r;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arrMap[i][j];
		}
	}

	
	int day = 0;

	while (true)
	{

		memset(visited, false, sizeof(visited));
		bool moved = false;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (visited[i][j]) continue;

				int sum = 0;
				queue<Node> Q;
				vector<Node> vUnit;
				Q.push(Node(i, j));
				visited[i][j] = true;
				vUnit.push_back(Node(i, j));
				sum += arrMap[i][j];
				

				while (!Q.empty())
				{
					Node now = Q.front(); Q.pop();

					for (int idx = 0; idx < 4; idx++)
					{
						int xx = now.X + dr[idx];
						int yy = now.Y + dc[idx];

						if (xx < 0 || yy < 0 || xx >= n || yy >= n) continue;
						if (visited[xx][yy]) continue;

						int absVal = abs(arrMap[now.X][now.Y] - arrMap[xx][yy]);

						if (absVal >= l && absVal <= r)
						{
							vUnit.push_back(Node(xx, yy));
							Q.push(Node(xx, yy));
							visited[xx][yy] = true;
							sum += arrMap[xx][yy];

						}
					}
				}
				// 하나의 연합에 대한 탐색이 끝?
				if (vUnit.size() >= 2)
				{
					int midVal = ( sum / vUnit.size() );

					for (Node item : vUnit)
					{
						arrMap[item.X][item.Y] = midVal;
					}
					moved = true;
				}


			}
		}
		if (!moved) break;
		day++;
	}

	cout << day;
	return 0;
}