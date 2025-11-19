#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int n;
int map[26][26];
int arrApt[26];
int arrAptIdx = 1; // 아파트 단지
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
	queue<Node> Q;
	
	cin >> n;

	string line;
	for (int i = 1; i <= n; i++)
	{
		cin >> line;
		for (int j = 1; j <= n; j++)
		{
			map[i][j] = line[j-1] - '0';
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
	
		for (int j = 1; j <= n; j++)
		{
			if(map[i][j] == 1)
			{
				
				Q.push(Node(i,j));
				map[i][j] = 0;
				arrApt[arrAptIdx] = 1;
				while(!Q.empty())
				{
					Node node = Q.front(); Q.pop();
					int x = node.X;
					int y = node.Y;
					
					for(int z=0; z<4; z++)
					{
						int xx = x + dx[z];
						int yy = y + dy[z];
						
						if (xx >= 1 && xx <= n && yy >= 1 && yy <= n && map[xx][yy] == 1)
						{
							Q.push(Node(xx, yy));
							arrApt[arrAptIdx] ++;
							map[xx][yy] = 0;
						}
					}
								
				}
				arrAptIdx++;
				
			} 
		}
	}
	
	cout << arrAptIdx << endl;

	for (int i = 1; i < arrAptIdx; i++)
	{
		cout << arrApt[i] << endl;
	}
	return 0;
	
	
	
//	Q.push(Node(1, 1));
//
//	while (1)
//	{
//		if (Q.empty())
//		{
//			arrAptIdx++;
//		}
//		Node node = Q.front(); Q.pop();
//		int x = node.X;
//		int y = node.Y;
//		
//		if (x > n || y > n) break;
//
//
//		for (int i = 0; i < 4; i++)
//		{
//			int xx = x + dx[i];
//			int yy = y + dy[i];
//
//			if (xx >= 1 && xx <= n && yy >= 1 && yy <= n)
//			{
//				Q.push(Node(xx, yy));
//			}
//		}

}
