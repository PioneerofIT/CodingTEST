#include <iostream>
#include <vector>
#include<queue>

using namespace std;
deque<int> vGear[4]; // 1:S극, 2:N극
int rotateDir[4] = { 0 }; // 1 : 시계방향, 0 : 회전 X, -1 : 반시계방향
void RotateGear(int gear, int dir)
{

	rotateDir[gear] = dir;

	//왼쪽 전파하면 왼쪽 기어들의 회전방향 결정
	for (int i = gear - 1; i >= 0; i--)
	{
		if (vGear[i][2] != vGear[i + 1][6])
		{
			rotateDir[i] = -rotateDir[i + 1];
		}
		else
		{
			rotateDir[i] = 0;
		}
	}

	for (int i = gear + 1; i < 4; i++)
	{
		if (vGear[i][6] != vGear[i - 1][2])
		{
			rotateDir[i] = -rotateDir[i - 1];
		}
		else
		{
			rotateDir[i] = 0;
		}
	}

	for (int i = 0; i < vGear->size(); i++)
	{
		if (rotateDir[i] == 1)
		{
			int last = vGear[i][7];
			vGear[i].pop_back();
			vGear[i].push_front(last);
		}
		else if (rotateDir[i] == -1)
		{
			int first = vGear[i][0];
			vGear[i].pop_front();
			vGear[i].push_back(first);
		}

	}


}


int main()
{

	for (int i = 0; i < 4; i++)
	{
		string line;
		cin >> line;

		for (int j = 0; j < line.size(); j++)
		{
			vGear[i].push_back(line[j] - '0');
		}
	}

	int k;
	cin >> k;

	while (k>0)
	{
		k--;
		int gear, dir;
		cin >> gear >> dir;

		RotateGear(gear-1, dir);
	}

	int totalSum = 0;

	if (vGear[0][0] == 1) totalSum += 1;
	if (vGear[1][0] == 1) totalSum += 2;
	if (vGear[2][0] == 1) totalSum += 4;
	if (vGear[3][0] == 1) totalSum += 8;

	cout << totalSum;
	
	return 0;
}