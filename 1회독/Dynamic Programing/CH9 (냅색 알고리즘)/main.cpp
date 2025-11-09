#include <iostream>
#include <vector> 
using namespace std;

int n,m; // n 종류, m 최대무게 

int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	
	int w,v;
	cin >> n >> m;
	vector<int> dy(m+1, 0);
	
	for(int i=0; i<n; i++)
	{
		cin >> w >> v;
		for(int j=w; j<=m; j++)
		{
			dy[j] = max(dy[j], dy[j-w]+ v);
		}
		
	}
	
	cout << dy[m];
	
	return 0;
}
