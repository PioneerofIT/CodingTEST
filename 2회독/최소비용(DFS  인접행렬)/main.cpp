#include <iostream>

using namespace std;

int nArrNum[21][21];
int ch[21];
int n,m; 

int nLessVel = 21470000;

void Move(int node , int sum)
{
	if(node == n)
	{
		if(sum < nLessVel)
		{
			nLessVel = sum;
		}
	}
	else
	{
		for(int i=1; i<=n; i++)
		{
			if(nArrNum[node][i] != 0 && ch[i] == 0 )
			{
				ch[i] = 1;
				Move(i, sum+nArrNum[node][i] );
				ch[i] = 0;
						
			}
		}
	}
}

int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int i=0; i<m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		
		nArrNum[a][b] = c; 
	}
	
	ch[1] = 1;
	Move(1, 0);
	
	cout << nLessVel;
	
	return 0;
}
