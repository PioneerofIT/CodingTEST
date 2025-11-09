#include <iostream>
#include <vector>
#include <algorithm> 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int map[21][21];
int ch[21];
int n;
/* 최소비용 문제는 다익스트라 알고리즘으로 쉽게 풀이 가능*/
int cost = 21470000;

void DFS(int v, int sum)
{
	if(v == n)
	{
		if(cost > sum)
		{
			cost = sum;
		}

	}
	else
	{
		for(int i=1; i<=n; i++)
		{
			if(map[v][i] != 0 && ch[i] == 0)
			{
				
				ch[i] = 1;
				DFS(i, sum+map[v][i] );
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
		int a,b,c;
		
		cin >> a >> b >> c;
		
		map[a][b] = c;
		 
	}
	
	ch[1] = 1;
	DFS(1, 0);
	cout << cost;

	

	return 0;
}

