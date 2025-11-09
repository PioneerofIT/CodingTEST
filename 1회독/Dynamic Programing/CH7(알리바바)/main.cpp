#include <iostream>
#include <algorithm>
using namespace std; 

int map[51][51];
int dy[51][51];
int n;

int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin >> map[i][j]; 
		}
	}
	
	dy[0][0] = map[0][0];
	
	for(int i=1; i<n; i++)
	{
		dy[0][i] = dy[0][i-1] + map[0][i];
		dy[i][0] = dy[i-1][0] + map[i][0];
	}
	
	for(int i=1; i<n; i++)
	{
		for(int j=1; j<n; j++)
		{
			dy[i][j] = min(dy[i-1][j], dy[i][j-1]) + map[i][j];
		}
	}
	
	cout << dy[n-1][n-1];

	return 0;
}
