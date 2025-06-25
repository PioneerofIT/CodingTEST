#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	
	vector<vector<int> > dy(n+1, vector<int> (n+1, 5000)) ;
	vector<int> res(n+1);
	for(int i=1; i<=n; i++) dy[i][i] = 0;
	int x,y;
	while(1)
	{
		cin >> x >> y;
		if(x == -1 && y == -1)
			break;
		else 
		{ 
			dy[x][y] = 1; // 무방향 그래프 
			dy[y][x] = 1;
		}
	}
	
	for(int k=1; k<=n; k++)
	{
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				dy[i][j] = min(dy[i][j], dy[i][k] + dy[k][j]);
			}
		}
	}
	
	int score= 100;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			res[i] = max(res[i], dy[i][j]);
		}
		score = min(score, res[i]);
	}
	int rescnt = 0;
	for(int i=1; i<=n; i++)
	{
		if(score == res[i]) rescnt ++;
	}
	cout << score << " " << rescnt << endl;
	
	for(int i=1; i<=n; i++)
	{
		if(score == res[i]) cout << i <<" ";
	}
	
	
	
	
	return 0;
}
