#include <iostream>
#include <climits>
#include <vector>
#include <cstring>
using namespace std;

struct Node
{
	int x;
	int y;
	Node(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

int n, m; //
int arrMap[50][50];
bool visited[13];
vector<Node> vHome;
vector<Node> vChick;
int minDistance = INT_MAX;

void Dfs(int idx, int L)
{
	if (L == m)
	{
		int sum = 0;
		for (int i = 0; i < vHome.size(); i++)
		{
			
			int minDist = INT_MAX;
			for (int j = 0; j < vChick.size(); j++)
			{
				if (visited[j])
				{
					Node now = vChick[j];
					int dist= abs(vHome[i].x - now.x) + abs(vHome[i].y - now.y);
					minDist = min(minDist, dist);
				}
			}
			sum += minDist;
		}
		minDistance = min(minDistance, sum);
		return;

	}
	else
	{
		for (int i = idx; i < vChick.size(); i++)
		{
			if (!visited[i])
			{
				visited[i] = true;
				Dfs(i + 1, L+1);
				visited[i] = false;

			}
		}
	}
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int val;
			cin >> val;
			arrMap[i][j] = val;
			if(val == 1)
			{
				vHome.push_back(Node(i, j));
			}
			else if (val == 2)
			{
				vChick.push_back(Node(i, j));
			}
		}
	}

	Dfs(0, 0);

	cout << minDistance;
	return 0;

}