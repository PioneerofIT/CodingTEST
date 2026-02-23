#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
struct Virus
{
	int x, y;

	Virus(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

int arrVirusMap[50][50];
int dr[4] = { 0, -1, 0, 1 };
int dc[4] = { 1, 0, -1, 0 };
bool visited[50];
bool visitedBfs[50][50];
int dist[50][50];
int N, M;
vector<Virus> vecVirus;
int minTime = INT_MAX;
int totalEmpty = 0;

void Bfs()
{
	queue<Virus> Q;
	
	memset(dist, 0, sizeof(dist));
	memset(visitedBfs, 0, sizeof(visitedBfs));

	int emptyCnt = totalEmpty;
	
	for (int i = 0; i < vecVirus.size(); i++)
	{
		if (visited[i])
		{
			Q.push(vecVirus[i]);
			visitedBfs[vecVirus[i].x][vecVirus[i].y] = true;
		}
	}


	int curMax = 0;
	while (!Q.empty())
	{
		Virus now = Q.front(); Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = now.x + dr[i];
			int ny = now.y + dc[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (arrVirusMap[nx][ny] == 1) continue;
			if (visitedBfs[nx][ny]) continue;


			dist[nx][ny] = dist[now.x][now.y] + 1;
			visitedBfs[nx][ny] = true;
			
			// 빈 칸인 경우에만 
			// 비활성 바이러스가 활성으로 변한 케이스는 포함하지 않는다
			if (arrVirusMap[nx][ny] == 0)
			{
				emptyCnt--;
				curMax = max(curMax, dist[nx][ny]);
			}		
			// 비활성 바이러스가 활성으로 변한 바이러스도 확산을 시작한다.
			Q.push(Virus(nx, ny));
		}
	}
	if (emptyCnt == 0)
	{
		minTime = min(minTime, curMax);
	}

}

void Dfs(int L, int idx)
{
	if (L == M)
	{
		Bfs();
	}
	else
	{
		for (int i = idx; i < vecVirus.size(); i++)
		{
			if (!visited[i])
			{
				visited[i] = true;
				Dfs(L + 1, i+1);
				visited[i] = false;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i <N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arrVirusMap[i][j];
			if (arrVirusMap[i][j] == 0)
			{
				totalEmpty++;
			}
			else if (arrVirusMap[i][j] == 2)
			{
				vecVirus.push_back(Virus(i, j));
			}
		}
	}

	Dfs(0, 0);
	if (minTime == INT_MAX)
	{
		cout << -1;
		
	}
	else
	{
		cout << minTime;
	}

	return 0;
}