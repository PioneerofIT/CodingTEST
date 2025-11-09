#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int map[1001][1001];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

struct Tomato
{
	int X;
	int Y;

	Tomato(int x, int y)
	{
		X = x;
		Y = y;
	}
};

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	queue<Tomato> Q;
	int totalDay = 0;
	bool IsAll = false;
	int n, m;// n = col, m = row

	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 1)
			{
				Q.push(Tomato(i, j));
			}
			else
			{
				IsAll = true;
			}
		}
	}

	if (Q.empty())
	{
		cout << -1 << endl;
		return 0;
	}

	if (!IsAll)
	{
		cout << 0 << endl;
		return 0;
	}

	while (!Q.empty()) {
	    int size = Q.size(); // 오늘 익을 토마토 개수
	    
	    for (int s = 0; s < size; s++) 
		{
	        Tomato t = Q.front(); 
			Q.pop();
	
	        for (int i = 0; i < 4; i++) 
			{
	            int xx = t.X + dx[i];
	            int yy = t.Y + dy[i];
	
	            if (xx >= 1 && xx <= m && yy >= 1 && yy <= n && map[xx][yy] == 0) 
				{
	                map[xx][yy] = 1;
	                Q.push(Tomato(xx, yy));
	            }
	        }
	    }
	    totalDay++; // 하루 경과
	}
	totalDay--; // 마지막 날 조정 (마지막은 이미 다 익은 상태)

	cout << totalDay;

	return 0;
}
