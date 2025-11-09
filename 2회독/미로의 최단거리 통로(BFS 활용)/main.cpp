#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int map[8][8];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int dist[8][8]; 

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
		
	ios_base::sync_with_stdio(false);
	
	int res = INT_MAX;
	int cnt = 0;
	queue<Node> Q;
	
	for(int i=1; i<=7; i++)
	{
		for(int j=1; j<=7; j++)
		{
			cin >> map[i][j];
		}
	}
	
	Q.push(Node(1,1));
	while(!Q.empty())
	{
		Node node = Q.front();
		Q.pop();
		
		for(int i=0; i<4; i++)
		{
			int xx = node.X + dx[i];
			int yy = node.Y + dy[i];
			
			
			if(xx >= 1  && yy >= 1 )
			{
				if(map[xx][yy] == 0 && dist[xx][yy] == 0)
				{
					dist[xx][yy] = dist[node.X][node.Y] + 1;
					Q.push(Node(xx, yy));
				}
			}
		}
		
	}
	if(dist[7][7] == 0) cout << -1;
	else cout << dist[7][7];

	
	return 0;
}
