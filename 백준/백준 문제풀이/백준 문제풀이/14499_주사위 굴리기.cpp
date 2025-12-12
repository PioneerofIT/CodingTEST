#include <iostream>
#include <queue>
using namespace std;
enum
{
	Top = 0,
	Back,
	Right,
	Left,
	Front,
	Bottom
};

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

int diceMap[20][20];
int n, m;
int x, y; // ¡÷ªÁ¿ß ¡¬«•
int k;
int statusDice[6];
int dr[4] = { 0, 0, -1, 1 }; // µøº≠∫œ≥≤
int dc[4] = { 1, -1, 0, 0 };// µøº≠∫œ≥≤
queue<Node> nodeQ;

void RollDice(int dir, Node nowNode)
{
	int nextX = nowNode.X + dr[dir-1];
	int nextY = nowNode.Y + dc[dir-1];

	if (nextX < 0 || nextX > n - 1 || nextY < 0 || nextY > m - 1)
	{
		nodeQ.push(Node(nowNode.X, nowNode.Y));
		return;
	}
	int backup[6];
	memcpy(backup, statusDice, sizeof(statusDice));
	switch (dir)
	{
		case 1: //µø
		{
			statusDice[Right] = backup[Top];
			statusDice[Bottom] = backup[Right];
			statusDice[Left] = backup[Bottom];
			statusDice[Top] = backup[Left];

		}break;
		case 2://º≠
		{
			statusDice[Left] = backup[Top];
			statusDice[Bottom] = backup[Left];
			statusDice[Right] = backup[Bottom];
			statusDice[Top] = backup[Right];
		}break;
		case 3://∫œ
		{
			statusDice[Back] = backup[Top];
			statusDice[Bottom] = backup[Back];
			statusDice[Front] = backup[Bottom];
			statusDice[Top] = backup[Front];
		}break;
		case 4://≥≤
		{
			statusDice[Front] = backup[Top];
			statusDice[Bottom] = backup[Front];
			statusDice[Back] = backup[Bottom];
			statusDice[Top] = backup[Back];
		}break;
	
		
	default:
		break;
	}

	if (diceMap[nextX][nextY] == 0)
	{
		diceMap[nextX][nextY] = statusDice[Bottom];
	}
	else
	{
		statusDice[Bottom] = diceMap[nextX][nextY];
		diceMap[nextX][nextY] = 0;
	}
	cout << statusDice[Top] << endl;
	nodeQ.push(Node(nextX, nextY));
}
int main()
{
	queue<int> orderQ;
	
	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> diceMap[i][j];
		}
	}

	for (int i = 0; i < k; i++)
	{
		int tmp;
		cin >> tmp;
		orderQ.push(tmp);

	}
	nodeQ.push(Node(x, y));

	while (!orderQ.empty())
	{
		int dir = orderQ.front(); orderQ.pop();

		Node nowNode = nodeQ.front(); nodeQ.pop();

		RollDice(dir, nowNode);
	}

	return 0;
}