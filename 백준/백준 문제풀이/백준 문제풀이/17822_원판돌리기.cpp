#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int N, M, T;
int dr[4] = { 0, -1, 0, 1 };
int dc[4] = { 1, 0, -1, 0 };
int arrCircleMap[51][51]; // 1-based
int sum = 0;

struct Node
{
	int X;
	int Y;
	Node(int x, int y)
	{
		X = x; Y = y;
	}
};
void DeleteCircle()
{
	queue<Node> Q;
	
	int arrTempCircleMap[51][51]; // 1-based
	int visited[51][51];
	bool IsDelete = false;
	memset(visited, false, sizeof(visited));
	memcpy(arrTempCircleMap, arrCircleMap, sizeof(arrTempCircleMap));
	
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++) 
		{
			if (visited[i][j]) continue;
			if (arrCircleMap[i][j] == -1) continue;      // FIX: 삭제값 스킵
			
			// BFS 돌리면 될 듯?
			Q.push(Node(i, j));
			visited[i][j] = true;

			while (!Q.empty())
			{
				Node nowNode = Q.front(); Q.pop();

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = nowNode.X + dr[dir];
					int ny = nowNode.Y + dc[dir];

					if (nx < 1 || nx > N) continue;   // 상하만 체크

					// 좌우는 원형 연결
					if (ny == 0) ny = M;
					else if (ny == M + 1) ny = 1;

					if (visited[nx][ny]) continue;
					if (arrCircleMap[nx][ny] == -1) continue;

					if (arrCircleMap[nowNode.X][nowNode.Y] == arrCircleMap[nx][ny])
					{
						arrTempCircleMap[nowNode.X][nowNode.Y] = -1;
						arrTempCircleMap[nx][ny] = -1;

						Q.push(Node(nx, ny));
						visited[nx][ny] = true;

						IsDelete = true;
					}


				}
			}




		}
	}

	if (!IsDelete)
	{
		double sumNum = 0;
		double cnt = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (arrTempCircleMap[i][j] == -1) continue;

				sumNum += (arrTempCircleMap[i][j]);
				cnt++;

			}
		}

		if (cnt > 0)
		{
			double avgNum = sumNum / cnt;
			for (int i = 1; i <= N; i++)
			{
				for (int j = 1; j <= M; j++)
				{
					if (arrTempCircleMap[i][j] != -1)
					{
						if (arrTempCircleMap[i][j] > avgNum) arrTempCircleMap[i][j]--;
						else if (arrTempCircleMap[i][j] < avgNum) arrTempCircleMap[i][j]++;
					}
				}
			}
		}

	}
	memcpy(arrCircleMap, arrTempCircleMap, sizeof(arrCircleMap));


}

void RotateCircle(int circleIdx, int dir)
{
	if (dir == 0) // 시계 방향
	{
		int temp = arrCircleMap[circleIdx][M];

		for (int i = M; i > 1; i--)
		{
			arrCircleMap[circleIdx][i] = arrCircleMap[circleIdx][i - 1];
		}
		arrCircleMap[circleIdx][1] = temp;
	}
	else if (dir == 1) // 반시계 방향
	{
		int temp = arrCircleMap[circleIdx][1];

		for (int i = 1; i < M; i++)
		{
			arrCircleMap[circleIdx][i] = arrCircleMap[circleIdx][i + 1];
		}
		arrCircleMap[circleIdx][M] = temp;

	}
}

void DecideCirCle(int x, int d, int k)
{
	vector<int> vecTargetCircle;
	vecTargetCircle.clear();

	//int arrTempCircleMap[51][51];
	//memset(arrTempCircleMap, 0, sizeof(arrTempCircleMap));


	for (int i = 1; i <= N; i++)
	{
		if (i % x == 0)
		{
			vecTargetCircle.push_back(i);
		}
	}

	for (int i = 0; i < vecTargetCircle.size(); i++)
	{
		int nCircleIdx = vecTargetCircle[i];

		for (int z = 0; z < k; z++)
		{
			RotateCircle(nCircleIdx, d);
		}

	}

	
}

int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> T;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arrCircleMap[i][j]; // row는 반지름 
		}
	}

	for (int i = 0; i < T; i++)
	{
		int x, d, k;
		cin >> x >> d >> k;


		DecideCirCle(x, d, k);
		DeleteCircle();
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (arrCircleMap[i][j] != -1)
			{
				sum += arrCircleMap[i][j];
			}
		}
	}
	cout << sum;
	
	return 0;
}