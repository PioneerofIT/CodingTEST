#include <iostream>

using namespace std;

int arrMap[8][8];
int chMap[8][8];
int cnt = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void Move(int x, int y)
{
	if(x == 7 && y == 7)
	{
		cnt ++;
	}
	else
	{
		for(int i=0; i<4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			
			if(xx >=1 && xx <=7  && yy>=1 && yy<=7)
			{
				if(arrMap[xx][yy] == 0 && chMap[xx][yy] == 0)
				{
					chMap[xx][yy] = 1;
					Move(xx, yy);
					chMap[xx][yy] = 0;
				}
			}
		}
	}
	
}

int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	
	for(int i=1; i<=7; i++)
	{
		for(int j=1; j<=7; j++)
		{
			cin >> arrMap[i][j];	
		}	
	}	
	
	chMap[1][1] = 1;
	
	Move(1,1);
	
	cout << cnt;
	return 0;
}
