#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int map[21][21];
int ch[21];
int n;
int count;

void DFS(int v)
{
	if(v == n)
	{
		count ++;	
	}
	else
	{
		for(int i=1; i<=n; i++)
		{
			if(map[v][i] == 1 && ch[i] == 0)
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
	
	int m;
	
	cin >> n >> m;
	
	for(int i=1; i<=m; i++)
	{
		int a,b;
		
		cin >> a >> b;
		
		map[a][b] = 1;
		 
	}
	
	ch[1] = 1;
	DFS(1);
	
	cout << count;
	
	return 0;
}
