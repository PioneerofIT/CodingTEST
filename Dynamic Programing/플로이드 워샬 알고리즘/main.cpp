#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	int n,m; // 도시 수, 도로 수
	
	cin >> n >> m;
	
	vector< vector<int>> dy(n+1, vector<int>(n+1, 5000));
	
	for(int i=0; i<m; i++)
	{
		int c1, c2, val;
		cin >> c1 >> c2 >> val;
		
		dy[c1][c2] = val;
	}
	
	for(int i=1; i<=n; i++) dy[i][i] = 0;
	
	for(int k=1; k<=n; k++)
	{
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				dy[i][j] = min(dy[i][j], dy[i][k]+dy[k][j]);
			}
		}
	}
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(dy[i][j] == 5000 ) cout << "M" <<" ";
			else cout << dy[i][j] << " ";
		}
		cout << endl;
	}
	
	
	 
	return 0;
}
