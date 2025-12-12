#include <iostream>
#include <queue>
using namespace std;

int boardMap[11][11];
int endX, endY;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int n, m;
bool visited[11][11][11][11];

struct ballState
{
	int Rx, Ry;
	int Bx, By;
	int Depth;
	ballState(int rx, int ry, int bx, int by, int dep)
	{
		Rx = rx; Ry = ry;
		Bx = bx; By = by;
		Depth = dep;
	}

};
queue<ballState> Q;
void DoRoll(int dir, ballState now, bool &IsRedHole , bool &IsBlueHole, int &outRx, int &outRy, int &outBx, int &outBy)
{
	//Red Roll
	int rollRx = now.Rx;
	int	rollRy = now.Ry;

	while (true)
	{
		int nextRx = rollRx + dx[dir];
		int nextRy = rollRy + dy[dir];
		if (nextRx == endX && nextRy == endY)
		{
			IsRedHole = true;
			rollRx = nextRx;
			rollRy = nextRy;
			break;
		}

		if (boardMap[nextRx][nextRy] == 1)
		{
			
			break;
		}


		
		rollRx = nextRx;
		rollRy = nextRy;


	}
	int rollBx = now.Bx;
	int	rollBy = now.By;
	//Blue Roll
	while (true)
	{
		int nextBx = rollBx + dx[dir];
		int nextBy = rollBy + dy[dir];


		if (nextBx == endX && nextBy == endY)
		{
			IsBlueHole = true;
			rollBx = nextBx;
			rollBy = nextBy;
			break;
		}

		if (boardMap[nextBx][nextBy] == 1)
		{
			break;
		}


		rollBx = nextBx;
		rollBy = nextBy;
	}


	if (rollRx == rollBx && rollRy == rollBy)// 충돌
	{
		int redDistance = abs(rollRx - now.Rx) + abs(rollRy - now.Ry);
		int blueDistance = abs(rollBx - now.Bx) + abs(rollBy - now.By);

		if (redDistance > blueDistance)
		{
			rollRx -= dx[dir];
			rollRy -= dy[dir];
		}
		else
		{
			rollBx -= dx[dir];
			rollBy -= dy[dir];
		}
	}
	outRx = rollRx;
	outRy = rollRy;
	outBx = rollBx;
	outBy = rollBy;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	int startRx, startRy;
	int startBx, startBy;

	string line;
	for (int i = 1; i <= n; i++)
	{
		cin >> line;
			
		for (int j = 1; j <= m; j++)
		{
			if (line[j - 1] == '#')
			{
				boardMap[i][j] = 1;
			}
			else if (line[j - 1] == '.')
			{
				boardMap[i][j] = 0;
			}
			else if (line[j - 1] == 'B')
			{
				startBx = i;
				startBy = j;
				boardMap[i][j] = 0;
			}
			else if (line[j - 1] == 'R')
			{
				startRx = i;
				startRy = j;
				boardMap[i][j] = 0;
			}
			else if (line[j - 1] == 'O')
			{
				endX = i;
				endY = j;
				boardMap[i][j] = -1;
			}
		}
	}
	Q.push(ballState(startRx, startRy, startBx, startBy, 0));

	while (!Q.empty())
	{
		ballState now = Q.front(); Q.pop();

		if (now.Depth >= 10)
		{
			cout << -1;
			return 0;
		}

		for (int i = 0; i < 4; i++)
		{
			bool isRedHole = false;
			bool isBlueHole = false;

			int nRx, nRy, nBx, nBy;
			DoRoll(i, now, isRedHole, isBlueHole, nRx, nRy, nBx, nBy);

			if (isBlueHole)
				continue;

			// 2. 여기까지 왔다는 건 파랑은 안 빠졌다는 뜻 → 빨강만 빠졌으면 성공
			if (isRedHole)
			{
				cout << (now.Depth + 1);
				return 0;
			}
			if (!visited[nRx][nRy][nBx][nBy])
			{
				visited[nRx][nRy][nBx][nBy] = true;
				Q.push(ballState(nRx, nRy, nBx, nBy, now.Depth + 1));
			}

		}

	}
	cout << -1;
	return 0;
}