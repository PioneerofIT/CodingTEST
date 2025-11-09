#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4]] = {1, 0, -1 , 0};

struct EoQ
{
	int x;
	int y;
	
	EoQ(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

int main(int argc, char** argv) 
{
	
	int map[8][8];
	int ch[8][8];
	queue<EoQ> Q;
	int minRes = 2147000000;
	
	for(int i=1; i<=7; i++)
	{
		for(int j=1; j<=7; j++)
		{
			cin >> map[i][j];
		}
	}
	
//	Q.push(1,1);
	ch[1][1] = 1;
	
//	while(!Q.empty())
//	{
//		
//		for(int i=0; i<4; i++) // dx, dy
//		{
//					
//		}
//	}
//	
	
	for(int i=0; i<4; i++) // dx, dy
	{
		Q.push(1,1);
		while(!Q.empty())
		{
			EoQ tmp = Q.front();
			Q.pop();
			for(int j=0; j<4; j++)
			{
			
				int xx = tmp.x + dx[j];
				int yy = tmp.y + dy[j];
				
				if(xx > 0 && yy > 0)
				{
					if(map[xx][yy] == 0 && ch[xx][yy] != 1 )
					{
						Q.push(EoQ(xx,yy));
						ch[xx][yy] = 1;
					}
				}
			}
			
		}			
	}
	
	
	
	
	
	return 0;
}
