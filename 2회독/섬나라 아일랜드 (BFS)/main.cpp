#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int map[21][21];
int n;

struct Node
{
	int X;
	int Y;
	
	Node(int x, int y)
	{
		X = x;
		Y = y;
	}
		
};

int main(int argc, char** argv) 
{
	cin >> n;
	queue<Node> Q;
	int cnt = 0;
	
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
				Q.push(Node(i, j));
				
				while(!Q.empty())
				{
					Node node = Q.front();
					Q.pop();
					int x = node.X;
					int y = node.Y;
					
					for(int z=0; z<8; z++)
					{
						int xx = x + dx[z];
						int yy = y + dy[z];
						
						if(xx > 0 && xx <= n && yy > 0 && yy <= n)
						{
							if(map[xx][yy] == 1)
							{
								Q.push(Node(xx, yy));
								map[xx][yy] = 0;
							}
						}
					}
				}
				cnt ++;
			}
		}
	}
	cout << cnt;
	return 0;
}
