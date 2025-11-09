#include <iostream>

using namespace std;

int map[21][21];
int n,m;
int Count = 0;
int ch[21];

void DFS(int L)
{
	if( L == n)
	{
		Count++;
	}
	else
	{
		for(int i=1; i<=n; i++)
		{
			if(map[L][i] == 1 && ch[i] == 0)
			{
				ch[i] = 1;
				DFS(i);
				ch[i] = 0;
			}
		}
	}
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	
	cin >> n >> m;
	
	for(int i=0; i<m; i++)
	{
		int a, b;
		
		cin >> a >> b;
		
		map[a][b] = 1;
	}
	
	for(int i=1; i<= n; i++) map[i][i] = 0;
	
	ch[1] = 1;
	
	DFS(1);
	
	cout << Count << endl;
	return 0;
}
