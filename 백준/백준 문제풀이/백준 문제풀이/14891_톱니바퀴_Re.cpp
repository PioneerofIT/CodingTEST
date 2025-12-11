#include <iostream>
#include <vector>
using namespace std;


vector<int> vGear[4];
int nGearDir[4]; // 1: 시계, 0 : 회전x, -1:반시계
int k;

void RotateGear(int gearIdx, int gearDir)
{
	nGearDir[gearIdx] = gearDir;

	for (int i = gearIdx - 1; i >= 0; i--) //왼쪽 전파
	{
		if (vGear[i][2] != vGear[i+1][6])
		{
			nGearDir[i] = -nGearDir[i + 1];
		}
		else
		{
			nGearDir[i] = 0;
		}
	}

	for (int i = gearIdx + 1; i < vGear->size(); i++)//오른쪽 전파
	{
		if (vGear[i][6] != vGear[i - 1][2])
		{
			nGearDir[i] = -nGearDir[i - 1];
		}
		else
		{
			nGearDir[i] = 0;
		}
	}

	for (int i = 0; i < vGear->size(); i++)
	{
		if (nGearDir[i] == 1) // 시계
		{
			int last = vGear[i][7];

			for (int j = 7; j > 0; j--)
			{
				vGear[i][j] = vGear[i][j - 1];
			}
			vGear[i][0] = last;

		}
		else if (nGearDir[i] == -1) // 반시계
		{

		}
	}

	
}
int main()
{

	for (int i = 0; i < vGear->size(); i++)
	{
		string line;
		cin >> line;

		for (int j = 0; j < line.size(); j++)
		{
			vGear[i].push_back(line[j] - '0');
		}
		
	}

	cin >> k;

	while (k > 0)
	{
		k--;
		int gearIdx, gearDir;
		cin >> gearIdx >> gearDir;



	}
	return 0;
}