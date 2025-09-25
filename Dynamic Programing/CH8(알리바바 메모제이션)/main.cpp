#include <iostream>
#include <algorithm>
using namespace std;

int n;
int data[21][21];
int dy[21][21];

int DFS(int x, int y)
{
	if(dy[x][y] > 0) return dy[x][y];
	
	if(x == 1 && y == 1) return data[1][1];
	else
	{
		if(x == 1) return dy[x][y] = DFS(x, y-1)+ data[x][y];
		else if( y == 1) return dy[x][y] = DFS(x-1, y)+ data[x][y];
		else return dy[x][y] = min( DFS(x,y-1), DFS(x-1, y) ) + data[x][y];				
	}
	
	
}

int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			cin >> data[i][j];
		}
	}
	
	cout << DFS(n,n);
	
	
	return 0;
}
