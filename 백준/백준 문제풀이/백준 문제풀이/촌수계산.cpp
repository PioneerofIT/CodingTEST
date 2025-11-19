#include <iostream>
#include <queue>
#include <vector>
using namespace  std;
int n;
int pNode, cNode;
int m;
vector<int> vNode[101];
bool visited[101];
int dist[101];  // 각 노드까지의 거리 (촌수)

int main()
{
	ios_base::sync_with_stdio(false);
	queue<int> Q;
	cin >> n;
	cin >> pNode >> cNode;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		vNode[x].push_back(y);
		vNode[y].push_back(x);
	}

	Q.push(pNode);
	visited[pNode] = true;
	dist[pNode] = 0;

	int cnt = 0;
	while (!Q.empty())
	{
		int node = Q.front(); Q.pop();
		if (node == cNode) break;

		for (int i = 0; i < vNode[node].size(); i++)
		{
			int nextNode = vNode[node][i];
			if (!visited[nextNode])
			{
				Q.push(nextNode);
				visited[nextNode] = true;
				dist[nextNode] = dist[node] + 1;
			}
		}

	}

	if (dist[cNode] == 0)
	{
		cout << -1;
	}
	else
	{
		cout << dist[cNode];
	}

	return 0;

}