#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	int n,m; // 전체 일의 개수와 순서 정보의 개수 
	cin >> n >> m;
	
	vector<vector<int> > graph(n+1, vector<int>(n+1, 0));
	vector<int> degree(m+1, 0);
	queue<int> Q;
	
	for(int i=1; i<=n; i++)
	{
		int a, b;
		cin >> a >> b;
		
		graph[a][b] = 1; // a->b 방향 간선 
		degree[b]++;	
	}
	
	for(int i=1; i<=n; i++)
	{
		if(degree[i] == 0)
		{
			Q.push(i);
		}
	}
	
	while(!Q.empty())
	{
		int now = Q.front();
		Q.pop();
		
		cout << now << " ";
		
		for(int i=1; i<=n; i++)
		{
			if(graph[now][i] == 1)
			{
				degree[i] --;
				if(degree[i] == 0) Q.push(i);
			}
		}
	}
		
	return 0;
}
