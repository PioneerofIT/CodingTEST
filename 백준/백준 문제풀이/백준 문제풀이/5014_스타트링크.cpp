#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
int f, s, g, u, d; // 건물 층수, 강호의 위치, 스타링크위치, 업 스텝, 다운 스텝
int dist[1000001];
bool visited[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	queue<int> Q;
	
	cin >> f >> s >> g >> u >> d;
	
	Q.push(s);
	visited[s] = true;

	while (!Q.empty())
	{
		int nowStatus = Q.front(); Q.pop();
		if (nowStatus == g)
		{
			break;
		}
		int nextStep[2] = { nowStatus + u, nowStatus - d };

		for (int i = 0; i < 2; i++)
		{
			if (nextStep[i] >= 1 && nextStep[i] <= f && !visited[nextStep[i]])
			{
				Q.push(nextStep[i]);
				dist[nextStep[i] ]= dist[nowStatus] + 1;
				visited[nextStep[i]] = true;
			}
		}

	}
	
	if (!visited[g])
		cout << "use the stairs";
	else
		cout << dist[g];
	return 0;
}