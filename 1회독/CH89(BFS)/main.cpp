#include <iostream>
#include <queue>
using namespace std;

int m,n; // 가로 세로 
int map[1001][1001];
int dist[1001][1001];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
struct LoC
{
	int x;
	int y;
	
	LoC(int x, int y)
	{
		this->x = x;
		this->y = y;	
	}	
};

int main(int argc, char** argv) 
{
	
	cin >> m >> n; //열 행 
	queue<LoC> Q;
	
	
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			cin >> map[i][j];
			if(map[i][j] == 1)
			{
				Q.push(LoC(i,j));
			}
			
		}
	}
	
	while(!Q.empty())
	{
		LoC tmp = Q.front();
		Q.pop();
		
		
		for(int i=0; i<4; i++)
		{
			int	xx = tmp.x + dx[i];
			int	yy = tmp.y + dy[i];
			
			if(xx > 0 && xx <= n && yy > 0 && yy <= m)
			{
				if(map[xx][yy] == 0)
				{
					map[xx][yy] = 1;
					dist[xx][yy] = dist[tmp.x][tmp.y] + 1;
					
					Q.push(LoC(xx, yy));		
				}	
			}	
		}
	}
	
	int final = 0;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			final = max(final, dist[i][j]);	
			
		}
	}
	cout << final;
	return 0;
}
