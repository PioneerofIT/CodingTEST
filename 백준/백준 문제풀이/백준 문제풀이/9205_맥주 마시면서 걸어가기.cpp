#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
	int X;
	int Y;
	Node(int x, int y)
	{
		X = x;
		Y = y;
	}

};

int main()
{
	ios_base::sync_with_stdio(false);


	int t, n;
	int StartX, StartY;
	int endX, endY;

	cin >> t;
	
	for (int testCase = 0; testCase < t; testCase++)
	{

		cin >> n;
		cin >> StartX >> StartY;
		vector<Node> vNode;      // 편의점 좌표 저장
		vector<bool> visited(n, false);   // 편의점 방문 여부

		for (int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			vNode.push_back(Node(a, b));
		}
		cin >> endX >> endY;

		queue<Node> Q;
		Q.push(Node(StartX, StartY));

		bool happy = false;
		while (!Q.empty())
		{
			Node now = Q.front(); Q.pop();

			int distToEnd = abs(now.X - endX) + abs(now.Y - endY);
			if (distToEnd <= 1000)
			{
				happy = true;
				break;
			}
				
			for (int j = 0; j < vNode.size(); j++)
			{
				if (!visited[j])
				{
					int x = vNode[j].X;
					int y = vNode[j].Y;

					int dist = abs(now.X - x) + abs(now.Y - y);

					if (dist <= 1000)
					{
						visited[j] = true;
						Q.push(Node(x, y));
					}
				}
			}
		}

		if (happy)
		{
			cout << "happy" << endl;
		}
		else
		{
			cout << "sad" << endl;
		}
	}
	return 0;
}

