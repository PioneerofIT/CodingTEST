#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m; // 컴퓨터의 수, 쌍
bool visited[101];
vector<int> vNode[101];

int main()
{
	ios_base::sync_with_stdio(false);
	queue<int> Q;

	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		vNode[a].push_back(b);
		vNode[b].push_back(a);
	}

	visited[1] = true;
	Q.push(1);

	int cnt = 0;
	while (!Q.empty())
	{
		int nowNode = Q.front(); Q.pop();

		for (int i = 0; i < vNode[nowNode].size(); i++)
		{
			int nextNode = vNode[nowNode][i];

			if (!visited[nextNode])
			{
				visited[nextNode] = true;
				Q.push(nextNode);
				cnt++;
			}
		}
	}

	cout << cnt;
	return 0;
}