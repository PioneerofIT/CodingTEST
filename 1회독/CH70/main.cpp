#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dis[30], ch[30];
int n;

int main(int argc, char** argv)
{
	int m;
	cin >> n >> m;
	
	vector<int> map[30];
	queue<int> Q;
	for(int i=0; i<m; i++)
	{
		int a, b;
		
		cin >> a >> b;
		map[a].push_back(b);
		
	}
	Q.push(1);
	ch[1]=1;
	int x;
	while(!Q.empty())
	{
		x = Q.front();
		Q.pop();
		
		for(int i=0; i<map[x].size(); i++)
		{
			if(ch[map[x][i]] == 0)
			{
				ch[map[x][i]] = 1;
				Q.push(map[x][i]);
				
				dis[map[x][i]] = dis[x] + 1;	
			} 
		}	
	}
		for(int i=2; i<=n; i++)
		{
			cout << i <<" :" <<" "<< dis[i] << endl;
			 
		}
	return 0;
}
