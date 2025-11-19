#include <iostream>
#include <queue>
using namespace std;

int n, k;
bool visited[100001];
int dist[100001];

int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	queue<int> Q;
	
	cin >> n >> k;
	
	visited[n] = true;
	Q.push(n);
	
	while(!Q.empty())
	{
		int nowLoc = Q.front(); Q.pop();
		
		if(nowLoc == k) break;
		
		int moves[3] = { nowLoc - 1, nowLoc + 1, nowLoc*2 };
		
		for(int nextLoc : moves)
		{
			if(nextLoc >= 0 && nextLoc <100001 && !visited[nextLoc] )
			{
				visited[nextLoc] = true;
				Q.push(nextLoc);
				dist[nextLoc] = dist[nowLoc] + 1;
			}
		}
	}
	
	cout << dist[k];
	
	return 0;
}
