#include <iostream>

using namespace std;

int map[21][21];

int n,m;
 
int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	
	cin >> n >> m;
	
	for(int i=1; i<=m; i++)
	{
		int a, b, c;
		
		cin >> a >> b >> c;
		
		map[a][b] = c; 
	}
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
