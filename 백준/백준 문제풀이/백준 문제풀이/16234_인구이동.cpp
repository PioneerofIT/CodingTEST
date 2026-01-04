#include <iostream>
#include <climits>
#include <vector>
#include <cstring>
#include <queue>
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
int arrArea[50][50];
bool visited[50][50];
int dr[4] = { 0, -1, 0, 1 };
int dc[4] = { 1, 0, -1, 0 };
int L, R;
int N;
int day = 0;


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> L >> R;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arrArea[i][j];
		}
	}

	while (true)
	{
		
		memset(visited, false, sizeof(visited));
		bool exitFlag = false;
	
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				//여기서 큐에 넣고 BFS 탐색시작
				
				if (visited[i][j]) continue;   //  이미 연합 처리됨

				//  BFS 시작 준비
				vector<Node> vUnit;            // 연합 좌표
				int sum = 0;                   // 연합 인구 합
				queue<Node> Q;                 // BFS 전용 큐

				visited[i][j] = true;
				Q.push(Node(i, j));
				vUnit.push_back(Node(i, j));
				sum += arrArea[i][j];

				while (!Q.empty())
				{
					// 큐에 노드 꺼내서 dr, dc방향 확인 후 인접한 나라들끼리 연합 맺을 수 있는지 판단
					Node now = Q.front(); Q.pop();

					for (int r = 0; r < 4; r++)
					{
						int nextX = now.x + dr[r];
						int nextY = now.y + dc[r];

						if (nextX < 0 || nextX > N || nextY < 0 || nextY > N) continue;
						if (visited[nextX][nextY]) continue;

						int diff = abs(arrArea[now.x][now.y] - arrArea[nextX][nextY]);

						// 연합이 가능하면 ??
						if (diff >= L && diff <= R)
						{
							visited[nextX][nextY] = true;  
							Q.push(Node(nextX, nextY));
							vUnit.push_back(Node(nextX, nextY));
							sum += arrArea[nextX][nextY];

						}

					}
				}


			}
		}

		if (vUnit.size() < 2)
		{
			exitFlag = true;
		}
		else
		{
			
			for (int x = 0; x < vUnit.size(); x++)
			{
				arrArea[vUnit[x].x][vUnit[x].y] = (int)(sum / vUnit.size());
			}
		}


		if (exitFlag)
			break;
	}

	


	return 0;
}