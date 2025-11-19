#include <iostream>
#include <queue>
#include <vector>
using namespace  std;
int n, m; // 컴퓨터 수와 간선 수
vector<int> vNode[101];
bool visited[101];

int main()
{
	ios_base::sync_with_stdio(false);
	queue<int> Q;
	int cnt = 0;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		vNode[a].push_back(b);
		vNode[b].push_back(a);

	}
	visited[1] = true;
	Q.push(1);

	while (!Q.empty())
	{
		int node = Q.front(); Q.pop();
	
		for (int i = 0; i < vNode[node].size(); i++)
		{
			if (!visited[vNode[node][i]])
			{
				visited[vNode[node][i]] = true;
				Q.push(vNode[node][i]);
				cnt++;
			}
			
		}

	}

	std::cout << cnt;
	return 0;
	

	
;}