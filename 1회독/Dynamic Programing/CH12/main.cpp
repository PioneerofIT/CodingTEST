#include <iostream>
#include <vector> 
using namespace std;

int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	int n,m;//도시 수, 도로 수
	
	cin >> n >> m;
	vector<vector<int> > dyDis(n+1, vector<int>(n+1, 5000));
	
	for(int i=1; i<=n; i++)
	{
		dyDis[i][i] = 0;
	}
	
	for(int i=0; i<m; i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		dyDis[a][b] = c;
		
	}
	
	for(int k=1; k<=n; k++)
	{
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				dyDis[i][j] = min(dyDis[i][j] , dyDis[i][k] +dyDis[k][j]  );
			}
		}
	}
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(dyDis[i][j] == 5000)
			{
				cout << "M" << " ";		
			}
			else
			{
				cout << dyDis[i][j] <<" " ;
			}
		}
		cout << endl;
	
	}
	 
	return 0;
}
