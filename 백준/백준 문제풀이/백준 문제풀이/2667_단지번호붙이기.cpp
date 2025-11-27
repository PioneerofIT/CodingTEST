#include <iostream>
#include <queue>
#include <algorithm>
#include<vector>
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

int n;
int aptMap[26][26];
bool visited[26][26];
int dx[4] = {0, 1, 0, -1};
int dy[4] = { 1, 0, -1, 0 };
vector<int> aptCnt;
//aptCnt[26 * 26] 으로 커버해야함
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	queue<Node> Q;

	cin >> n;
	string line;
	for (int i = 1; i <= n; i++)
	{
		cin >> line;
		for (int j = 1; j <= n; j++)
		{
			aptMap[i][j] = line[j - 1] - '0';
		}
	}
	int aptIdx = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (aptMap[i][j] == 1 && !visited[i][j])
			{
				visited[i][j] = true;
				aptIdx++;
				Q.push(Node(i, j));
				int cnt = 1;
			
				while (!Q.empty())
				{
					Node now = Q.front(); Q.pop();
					int x = now.X;
					int y = now.Y;

					for (int z = 0; z < 4; z++)
					{
						int xx = x + dx[z];
						int yy = y + dy[z];

						if (xx >= 1 && xx <= n && yy >= 1 && yy <= n && aptMap[xx][yy] == 1 && !visited[xx][yy])
						{
							visited[xx][yy] = true;
							Q.push(Node(xx, yy));
							cnt++;
						}

					}
				}
				aptCnt.push_back(cnt);
			}
		}
	}
		//sort(aptArr + 1, aptArr + aptIdx + 1); // 배열의 처음주소부터 마지막까지 정렬 sort[first, last)  마지막은 개구간임
	sort(aptCnt.begin(), aptCnt.end());
	cout << aptIdx << endl;
	for (int a=0; a<aptCnt.size(); a++)
	{
		cout << aptCnt[a] << endl;
	}

	return 0;

	
}
