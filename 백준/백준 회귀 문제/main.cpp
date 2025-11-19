#include <iostream>
#include <queue>
using namespace std;

int f, s, g, u, d;
int dist[1000001];
bool visited[1000001];

int main(int argc, char** argv) 
{
	cin >> f >> s >> g >> u >> d;
	queue<int> Q;
	
	visited[s] = true;
	Q.push(s);
	
	while(!Q.empty())
	{
		int now = Q.front(); Q.pop();
		
		if(now == g) break;  
		
		int moves[2] = { now + u, now - d};
		
		for(int nextNode : moves)
		{
			if(nextNode >=1 && nextNode <= f && !visited[nextNode]  )
			{
				visited[nextNode] = true;
				Q.push(nextNode);
				dist[nextNode] = dist[now] + 1;
			}
		}
	}
	
	if(!visited[g] ) cout << "use the stairs";
	else cout << dist[g];
	
	return 0;
}
