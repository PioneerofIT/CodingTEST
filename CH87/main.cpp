#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};
int map[21][21];
int n;


struct EoQ
{
	int x;
	int y;
	
	EoQ (int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};
int main(int argc, char** argv) 
{
	
	cin >> n;
	int cnt = 0;
	queue<EoQ> Q;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			cin >> map[i][j];	
		}	
	}
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(map[i][j] == 1)
			{
				Q.push(EoQ(i,j));
				
				while(!Q.empty())
				{
					EoQ tmp = Q.front();
					Q.pop();
					
					for(int k=0; k<8; k++)
					{
						int xx = tmp.x + dx[k];
						int yy = tmp.y + dy[k];
						
						if(map[xx][yy] == 1)
						{
							map[xx][yy] = 0;
							Q.push(EoQ(xx,yy));	
						}
					}
				}
				cnt++;
					
			}	
		}	
	}	
	cout << cnt;
	return 0;
}
