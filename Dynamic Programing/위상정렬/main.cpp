#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	int n,m; // 일의 갯수(노드) , 순서 정보
	cin >> n >> m;
	
	vector<vector<int>> graph(n+1, vector<int>(n+1, 0));
	vector<int> degree(n+1, 0);
	queue<int> Q;
	
	for(int i=0; i<m; i++)
	{
		int s, d; //출발, 도착 
		
		cin >> s >> d;
		graph[s][d] = 1;
		degree[d]++;
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
			if(graph[now][i] != 0 )
			{
				degree[i] --;
				if(degree[i] == 0)
				{
					Q.push(i);
				}
			}
		}
			
	}
	
	
	 
	return 0;
}
