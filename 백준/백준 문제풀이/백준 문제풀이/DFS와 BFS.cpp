#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, v;
vector<int> vNode[1001];
int ch[1001];
int res[1001];

void DFS(int startnode)
{
	cout << startnode << " ";
	ch[startnode] = 1;  //  방문 표시

	for (int i = 0; i < vNode[startnode].size(); i++)
	{
		int nextNode = vNode[startnode][i];
		if (ch[nextNode] == 0)   // 아직 방문 안 한 노드면
		{
			DFS(nextNode);       //  재귀 호출
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	queue<int> Q;
	cin >> n >> m >> v;

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		vNode[a].push_back(b);
		vNode[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) 	sort(vNode[i].begin(), vNode[i].end());

	ch[v] = 1;
	DFS(v);

	//BFS
	for (int i = 1; i <= n; i++) ch[i] = 0;

	cout << endl;

	Q.push(v);
	ch[v] = 1;

	while (!Q.empty())
	{
		int nowNode = Q.front();
		Q.pop();
		cout << nowNode << " ";

		for (int i = 0; i < vNode[nowNode].size(); i++)
		{
			if (ch[vNode[nowNode][i]] == 0)
			{
				Q.push(vNode[nowNode][i] );
				ch[vNode[nowNode][i]] = 1;
			}
		}
	}
	

	return 0;

	
}