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
bool visited[65];
bool arrVisited[9][9];
vector<Node> vWallList;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
queue<Node> Q;
int maxSafyArea = INT_MIN;
void SpreadVirusBfs()
{
	while (!Q.empty()) Q.pop();
	int arrBackup[9][9];
	memcpy(arrBackup, arrMap, sizeof(arrMap));


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (arrMap[i][j] == 2)
			{
				Q.push(Node(i, j)); // Start 확산

				while (!Q.empty())
				{
					Node now = Q.front(); Q.pop();

					for (int z = 0; z < 4; z++)
					{
						int xx = now.X + dx[z];
						int yy = now.Y + dy[z];

						if (xx < 1 || xx >n || yy<1 || yy >m || arrMap[xx][yy] == 1) continue; // 벽이거나 경계박이면 나와서 ..

						if (arrMap[xx][yy] == 0)
						{
							arrMap[xx][yy] = 2; // 아니면
							Q.push(Node(xx, yy));
						}
							

					}
				}

			}
		}
	}

	int sumCnt = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j<= m; j++)
		{
			if (arrMap[i][j] == 0)
			{
				sumCnt++;
			}
		}
	}

	maxSafyArea = max(maxSafyArea, sumCnt);

	memcpy(arrMap, arrBackup, sizeof(arrBackup));
}


void InstallWallDfs(int startidx, int cnt)
{
	if (cnt == 3)
	{
		SpreadVirusBfs();
		return;
	}
	else
	{
		for (int i = startidx; i < vWallList.size(); i++)
		{
			arrMap[vWallList[i].X][vWallList[i].Y] = 1; // 벽설치
			InstallWallDfs(i+1, cnt + 1);
			arrMap[vWallList[i].X][vWallList[i].Y] = 0; // 벽 복구

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

	InstallWallDfs(1,0);
	
	cout << maxSafyArea;

}