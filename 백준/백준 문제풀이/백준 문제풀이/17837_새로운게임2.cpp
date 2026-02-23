#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <stack>
using namespace std;

//1-based
struct Horse
{
	int x, y;
	int dir;

	Horse(int x, int y,  int dir)
	{
		this->x = x;
		this->y = y;
		this->dir = dir;
	}
};
int turnCnt = 0;
int arrBoard[13][13];
int N, K;
int dr[5] = { 0, 0, 0, -1, 1 };
int dc[5] = { 0, 1, -1, 0, 0 };
int revDir[5] = { 0, 2, 1, 4, 3 }; // 1<->2, 3<->4
vector<int> vHorseMap[13][13];
vector<Horse> vHorseInfo;

bool MoveHorse()
{
	for (int i = 1; i <= K; i++)
	{
		Horse &horse = vHorseInfo[i];

		int nx = horse.x + dr[horse.dir];
		int ny = horse.y + dc[horse.dir];

		if (nx < 1 || nx > N || ny < 1 || ny > N || arrBoard[nx][ny] == 2)
		{
			//방향 전환
			vHorseInfo[i].dir = revDir[horse.dir];
			int nx2 = horse.x + dr[vHorseInfo[i].dir];
			int ny2 = horse.y + dc[vHorseInfo[i].dir];

			// 2) 두 번째 칸도 범위 밖이면 "파랑"과 동일 => 이동 안 함
			if (nx2 < 1 || nx2 > N || ny2 < 1 || ny2 > N || arrBoard[nx2][ny2] == 2)
				continue;

			nx = nx2; ny = ny2;
		}

		vector<int> vecTmp;
		vecTmp.clear();

		//현재 좌표에 있는 말들 찾기
		for (int j = vHorseMap[horse.x][horse.y].size()-1; j >=0 ; j--)
		{
			int now = vHorseMap[horse.x][horse.y][j];
			// pop해야하는데
			vHorseMap[horse.x][horse.y].pop_back();
			vecTmp.push_back(now);

			Horse& nextHorse = vHorseInfo[now];
			nextHorse.x = nx;
			nextHorse.y = ny;
			if (now == i)
			{
				break;
			}
		} 

		if (arrBoard[nx][ny] == 0)
		{
			for (int idx = (vecTmp.size() - 1); idx >= 0; idx--)
			{
				vHorseMap[nx][ny].push_back(vecTmp[idx]);
			}
		}
		else if (arrBoard[nx][ny] == 1)
		{
			for (int idx = 0;  idx<vecTmp.size(); idx++)
			{
				vHorseMap[nx][ny].push_back(vecTmp[idx]);
			}
		}

		if (vHorseMap[nx][ny].size() >= 4)
		{
			return true;
		}


	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arrBoard[i][j];
		}
	}
	vHorseInfo.push_back(Horse(0, 0, 0));
	for (int i = 1; i <= K; i++)
	{
		int x, y, dir;
		cin >> x >> y >> dir;

		vHorseInfo.push_back(Horse(x, y, dir));
		vHorseMap[x][y].push_back(i);

	}

	for (int turn = 1; turn <= 1000; turn++)
	{
		if (MoveHorse())
		{
			cout << turn;
			return 0;
		}
	}
	cout << -1;
	return 0;
}