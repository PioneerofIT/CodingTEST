#include <iostream>
#include <vector>
#include <cstring>
#include<climits>
using namespace std;

struct CctvNode
{
	int x;
	int y;
	int type;

	CctvNode(int x, int y, int type)
	{
		this->x = x;
		this->y = y;
		this->type = type;
	}

};
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int arrMap[8][8];
int n, m;
int minArea = INT_MAX;
vector<CctvNode> vCctvNdoe;
vector<vector<int>> vCctvDir[6] =
{
	{  },
	{{0},{1},{2},{3}},
	{{1, 3}, {0, 2 } },
	{{0,1}, {1,2},{2,3},{3,0} },
	{ { 3, 0, 1 }, {0,1,2 }, {1, 2, 3 }, {2, 3, 0 } },
	{{0,1,2,3}}

};


void Dfs(int idx, int map[8][8])
{
	if (idx == (int)vCctvNdoe.size())
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] == 0) cnt++;
			}
		}
		minArea = min(minArea, cnt);
		
	}
	else
	{
		int x = vCctvNdoe[idx].x;
		int y = vCctvNdoe[idx].y;
		int type = vCctvNdoe[idx].type;

		for (const auto& opt : vCctvDir[type]) // {0,1}, {1,2},{2,3},{3,0}
		{
			int temp[8][8];
			memcpy(temp, map, sizeof(temp));

			for (int dir : opt)
			{
				int xx = x + dx[dir];
				int yy = y + dy[dir];

				while (xx >= 0 && xx < n && yy >= 0 && yy < m )
				{
					if (temp[xx][yy] == 6) break;
					if (temp[xx][yy] == 0) temp[xx][yy] = -1;

					xx += dx[dir];
					yy += dy[dir];
				}
			}
			Dfs(idx + 1, temp);
			
		}
	}
}

int main()
{
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arrMap[i][j];
			if (arrMap[i][j] >= 1 && arrMap[i][j] <= 5)
			{
				vCctvNdoe.push_back(CctvNode(i, j, arrMap[i][j]));
			}
		}
	}
	
	Dfs(0,arrMap );

	cout << minArea;
	
	return 0;

	
}