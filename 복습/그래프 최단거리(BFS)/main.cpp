#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dist[21];
int ch[21];
int n,m;
vector<int> graph[21];

int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	queue<int> Q;
	
	cin >> n >> m;
	
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		
		graph[a].push_back(b);
	}
	
	Q.push(1);
	ch[1] = 1;
	
	while(!Q.empty())
	{
		int v = Q.front();
		Q.pop();
		
		for(int i=0; i<graph[v].size(); i++)
		{
			int nextnode = graph[v][i];
			
			if(ch[nextnode] == 0)
			{
				ch[nextnode] = 1;
				dist[nextnode]	= dist[v] +1;
				Q.push(nextnode); 	
			}

		}	
	
	} 
	
	for(int i=2; i<=n; i++)
	{
		cout << i << " : " << dist[i] << endl;
	}
	
	
	return 0;
}
