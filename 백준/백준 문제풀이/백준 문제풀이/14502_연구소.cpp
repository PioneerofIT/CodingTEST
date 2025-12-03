#include <iostream>
#include <vector>
#include<queue>
#include <cstring>
#include <climits>
using namespace std;
struct Node
{
	int X, Y;
	Node(int x, int y)
	{
		X = x;
		Y = y;
	}
	
};

int arrMap[9][9];
int n,m;
bool visited[25];
vector<Node> vWallList;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
queue<Node> Q;


void InstallWallDfs( int cnt)
{
	if (cnt == 3)
	{
		SpreadVirusBfs();
		return;
	}
	else
	{
		for (int i = 1; i <= vWallList.size(); i++)
		{
			if (!visited[i])
			{
				visited[i] = true;
				InstallWallDfs(cnt + 1);
				visited[i] = false;
			}
		}
	}
}

void SpreadVirusBfs()
{
	int arrBackup[9][9];
	memcpy(arrBackup, arrMap, sizeof(arrMap));

	for (int i = 1; i <= vWallList.size(); i++) // º® ¼³Ä¡
	{
		if (visited[i])
		{
			int installX = vWallList[i].X;
			int installY = vWallList[i].Y;

			arrMap[installX][installY] = 1;
		}
	}


	
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	vWallList.push_back(Node(0, 0)); // No use Idx 0 
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> arrMap[i][j];
			if (arrMap[i][j] == 0)
			{
				vWallList.push_back(Node(i, j));
			}
		}
	}
	


}