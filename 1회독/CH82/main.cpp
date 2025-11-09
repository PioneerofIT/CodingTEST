#include <iostream>
#include <vector>
using namespace std;
int res[20];
int ch[20];
int a[20];
int cnt = 0;
int n, m;
void DFS(int L)
{
	if( L== m )
	{
		for(int i=0; i<m; i++)
		{
			cout << res[i] <<" ";	
		}
		cout << endl;
		cnt ++;	
	}
	else
	{
		for(int i=0; i<n; i++)
		{
			if( ch[i] == 0)
			{
				ch[i] = 1;
				res[L] = a[i];
				DFS(L+1);
				ch[i] = 0;	
			}			
		}

	}
}

int main(int argc, char** argv) 
{
	
	
	cin >> n >> m;
	
	for(int i=0; i<n; i++)
	{
		int temp;
		
		cin >> temp;
		
		a[i] = temp;
	}
	DFS(0);
	
	cout << cnt;
	
	return 0;
}
