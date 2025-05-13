#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int> > map[30];
int ch[30];
int n;
int minPrice = 21470000;

void DFS(int v, int sum)
{
	if(v == n)
	{
		if(minPrice > sum )
		{
			minPrice = sum;
		}	
	}
	else
	{
		for(int i=0; i<map[v].size(); i++)
		{
			if(ch[map[v][i].first] == 0)
			{
				ch[map[v][i].first] = 1;
				DFS(map[v][i].first, sum+map[v][i].second )	;
				ch[map[v][i].first] = 0;
			}
		}
	}
}
int main(int argc, char** argv) 
{
	
	int m;
	
	cin >> n >> m;
	
	
	for(int i=0; i<m; i++ )
	{
		int a, b, c;
		cin >> a >> b >> c;
		
		map[a].push_back(make_pair(b,c));
	}
	
	ch[1] = 1;
	DFS(1,0);
	
	cout << minPrice;
	return 0;
}

