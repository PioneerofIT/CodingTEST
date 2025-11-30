#include <iostream>
#include<vector>
#include <queue>

using namespace std;

int boardMap[101][101];

int N, K, L; // 보드판, 사과의 갯수, 방향 횟수
int gameTime; // 게임 경과 시간
int dr[4] = { 0, 1, 0, -1 }; // row 변화
int dc[4] = { 1, 0, -1, 0 }; // col 변화

/*중요 !!!! : Row Col 기반 방향을 설정하는 문제는 일반 x y 기준으로 방향설정하면 안된다... 헷갈리지 않게 dx, dy가 아닌 dr dc로 정의하자*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<pair<int, char> > DirInfo;
	deque<pair<int, int>> dqSnake;
	int dir = 0;

	cin >> N;
	cin >> K;

	for (int i = 0; i < K; i++)// 사과 위치 초기화
	{
		int a, b;
		cin >> a >> b;
		boardMap[a][b] = 1;
	}
	cin >> L;

	for (int i = 0; i < L; i++)
	{
		int t;
		char a;
		cin >> t >> a;

		DirInfo.push_back(make_pair(t, a)); // (3,D) (15,L) (17,D)
	}

	dqSnake.push_front(make_pair(1, 1));
	boardMap[1][1] = 2;

	gameTime = 0;
	int idx = 0;
	while (true)
	{
		
		
		int headX = dqSnake.front().first;
		int headY = dqSnake.front().second;

		int nextHeadX = headX + dr[dir];
		int nextHeadY = headY + dc[dir];

		gameTime++;

		if (nextHeadX < 1 || nextHeadX >N || nextHeadY < 1 || nextHeadY >N) break;

		if (boardMap[nextHeadX][nextHeadY] == 2) break;

		if (boardMap[nextHeadX][nextHeadY] == 1) // 사과가 있다면
		{
			boardMap[nextHeadX][nextHeadY] = 2;
			dqSnake.push_front(make_pair(nextHeadX, nextHeadY));
			
		}
		else 
		{
			dqSnake.push_front(make_pair(nextHeadX, nextHeadY));
			boardMap[nextHeadX][nextHeadY] = 2;
			pair<int, int> tmp = dqSnake.back();
			boardMap[tmp.first][tmp.second] = 0;
			dqSnake.pop_back();
		}


	
		if (idx < L && DirInfo[idx].first == gameTime)
		{
			if (DirInfo[idx].second == 'L') // 왼쪽 90
			{
				dir = (dir + 3) % 4;
			}
			else // 오른쪽 90
			{
				dir = (dir + 1) % 4;
			}
			idx++;
		}


	}
	cout << gameTime;

	return 0;
}
