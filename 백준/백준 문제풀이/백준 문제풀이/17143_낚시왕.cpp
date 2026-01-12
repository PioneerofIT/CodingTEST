#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Shark
{
	int x = 0, y = 0;
	int dir = 0;
	int size = 0;
	int vel = 0;
	bool alive = false;

	Shark() {} 

	Shark(int x, int y, int vel, int dir, int size, bool alive)
	{
		this->x = x;
		this->y = y; 
		this->vel = vel;
		this->dir = dir;
		this->size = size;
		this->alive = alive;
	}
};

int r, c, m;
int dr[5] = {0, -1, 1, 0, 0 }; // idx 0사용안함 1:위 2:아래 3:오른쪽 4:왼쪽
int dc[5] = { 0, 0, 0, 1, -1 }; // idx 0사용안함 1:위 2:아래 3:오른쪽 4:왼쪽
Shark SharkState[10001];
int arrSharkMap[101] [101] ;
int fishingMan = 0;
int sumSize = 0;
void CatchShark()
{
	for (int i = 1; i <= r; i++)
	{
		if (arrSharkMap[i][fishingMan] > 0  )
		{
			int sharkId = arrSharkMap[i][fishingMan];
			sumSize += SharkState[sharkId].size;
			SharkState[sharkId].alive = false;
			arrSharkMap[i][fishingMan] = 0;
			break;
		}
	}
}

void MoveShark()
{
	int arrTemp[101][101];
	memset(arrTemp, 0, sizeof(arrTemp));

	for (int i = 1; i <= m; i++)
	{
		if (!SharkState[i].alive) continue;

		//매우 중요 !! 참조로 처리하여 값 변경
		Shark &shark = SharkState[i];

		int move = shark.vel;

		// 제자리로 오는 경우를 제외한 실제 움직이는 칸의 수
		// 주기를 구하지 않을 경우 시간초과..
		// 세로 이동
		if (shark.dir == 1 || shark.dir == 2)
		{
			move %= (r - 1) * 2;
		}	
		// 가로 이동
		else
		{
			move %= (c - 1) * 2;
		}
			

		for (int j = 0; j < move; j++)
		{
			int nx = shark.x + dr[shark.dir];
			int ny = shark.y + dc[shark.dir];

			if (nx < 1 || nx > r || ny < 1 || ny > c) // 방향전환
			{
				if (shark.dir == 1) shark.dir = 2;
				else if (shark.dir == 2) shark.dir = 1;
				else if (shark.dir == 3) shark.dir = 4;
				else if (shark.dir == 4) shark.dir = 3;

				nx = shark.x + dr[shark.dir];
				ny = shark.y + dc[shark.dir];
			}
			shark.x = nx;
			shark.y = ny;
		}

		if (arrTemp[shark.x][shark.y] != 0)
		{
			// 기존 map에 있는 상어 id
			int targetId = arrTemp[shark.x][shark.y];
			Shark &target = SharkState[targetId];

			//기존이랑 새로운 상어랑 사이즈 비교
			if (target.size > shark.size)
			{
				shark.alive = false;
				continue; // 더이상 처리하지 않음
			}
			else //기존 상어는 죽이고 새로운 상어가 arrTemp에 id
			{
				target.alive = false;
				arrTemp[shark.x][shark.y] = i; // i는 새로운 상어 id
			}

		}
		else
		{
			arrTemp[shark.x][shark.y] = i;
		}
		

	}
	memcpy(arrSharkMap, arrTemp, sizeof(arrTemp));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> r >> c >> m;

	int sharkId = 1;
	for (int i = 0; i < m; i++)
	{
		int row, col, s, d, z;
		
		cin >> row >> col >> s >> d >> z;
		arrSharkMap[row][col] = sharkId;
		SharkState[sharkId] = Shark(row, col, s, d, z, true);
		sharkId++;

	}

	while (true)
	{
		fishingMan++;

		if (fishingMan > c) break;

		CatchShark();
		MoveShark();
	}
	
	cout << sumSize;
	return 0;
}
