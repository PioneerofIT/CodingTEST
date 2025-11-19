#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
int n, k; // 수빈이와 동생의 현재 위치
bool visited[100001];
int dist[100001];
queue<int> Q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;

	Q.push(n);

	while (!Q.empty())
	{
		int nextNode = Q.front(); Q.pop();

		if (nextNode == k) break;

		int move[3] = { nextNode - 1, nextNode + 1, nextNode * 2 };

		for (int nx : move)
		{
			if (nx >= 0 && nx <= 100000 && !visited[nx])
			{
				Q.push(nx);
				visited[nx] = true;
				dist[nx] = dist[nextNode] + 1;
			}
		}
	}
	cout << dist[k];
	return 0;

}