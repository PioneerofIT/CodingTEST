#include <iostream>

using namespace std;

int map[8][8];
int count = 0;
int ch[8][8];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void DFS(int x, int y)
{
	int xx, yy;
	if( x == 7 && y == 7 )	
	{
		count ++;
	}
	else
	{
		for(int i=0; i<4; i++)
		{
			xx = x + dx[i];
			yy = y + dy[i];
			
			if(xx<1 || xx>7 || yy<1 || yy>7) continue;
			
			if(map[xx][yy] == 0 && ch[xx][yy] == 0)
			{
				ch[xx][yy] = 1;
				DFS(xx, yy);
				ch[xx][yy] = 0;
			}
		}
	}
}

int main(int argc, char** argv) 
{
	
	for(int i=1; i<=7; i++)
	{
		for(int j=1; j<=7; j++)
		{
			int value;
			cin >> value;
			
			map[i][j] = value;
		}
	}
	
	ch[1][1] =1;
	DFS(1,1);

	
	cout << count;
	return 0;
}
