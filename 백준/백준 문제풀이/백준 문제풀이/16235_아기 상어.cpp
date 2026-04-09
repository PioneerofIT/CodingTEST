#include <iostream>
#include <climits>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

struct Shark
{
	int x, y;
	int ate;
	int lev;

	void DoAte()
	{
		ate++;
		if (ate == lev) 
		{
			lev++;
			ate = 0;
		}
	}
};

struct Node
{
	int x, y;

	Node(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	bool operator< (const Node& arg) const
	{
		if (this->x != arg.x)  return this->x < arg.x;
		return this->y < arg.y;
	}
};
int dr[4] = { 0, -1, 0, 1 };
int dc[4] = { 1, 0, -1, 0 };
int arrMap[20][20];
int dist[20][20];
int n;
int t = 0;
int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	Shark shark;
	shark.lev = 2;
	shark.ate = 0;

	queue<Node> Q;
	vector<Node> vCandidate;


	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arrMap[i][j];

			if (arrMap[i][j] == 9)
			{
				shark.x = i;
				shark.y = j;
				arrMap[i][j] = 0;
			}
		}
	}
	

	while (true)
	{
		memset(dist, -1, sizeof(dist));
		while (!Q.empty()) Q.pop();
		vCandidate.clear();

		Q.push(Node(shark.x, shark.y));
		dist[shark.x][shark.y] = 0;

		int minDist = INT_MAX;

		while (!Q.empty())
		{
			Node cur = Q.front(); Q.pop();

			if (dist[cur.x][cur.y] > minDist) break;

			for (int i = 0; i < 4; i++)
			{
				int nx = cur.x + dr[i];
				int ny = cur.y + dc[i];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (dist[nx][ny] != -1) continue;
				if (arrMap[nx][ny] > shark.lev) continue;

				int nowDistance = dist[nx][ny] = dist[cur.x][cur.y] + 1;

				if (arrMap[nx][ny] != 0 && arrMap[nx][ny] < shark.lev)
				{
					if (nowDistance < minDist)
					{
						minDist = nowDistance;
						//vCandidate.clear();
						vCandidate.push_back(Node(nx, ny));
						
					}
					else if (minDist == nowDistance)
					{
						vCandidate.push_back(Node(nx, ny));
					}

				}
				Q.push(Node(nx, ny));
				
			}

			
		}

		if (vCandidate.size() == 0) break;

		sort(vCandidate.begin(), vCandidate.end());

		Node ate = vCandidate[0];
		t += dist[ate.x][ate.y];

		shark.x = ate.x;
		shark.y = ate.y;
		arrMap[ate.x][ate.y] = 0;

		shark.DoAte();


	}


	cout << t;
	return 0;
}