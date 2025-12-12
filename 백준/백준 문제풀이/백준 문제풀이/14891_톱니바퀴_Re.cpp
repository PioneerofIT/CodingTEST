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

	for (int i = gearIdx + 1; i <4; i++)//오른쪽 전파
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

	for (int i = 0; i < 4; i++)
	{
		if (nGearDir[i] == 1) // 시계
		{
			int last = vGear[i][7];
			for (int j = vGear->size() - 1; j > 0; j--)
			{
				vGear[i][j] = vGear[i][j - 1];
			}
			vGear[i][0] = last;
		}
		else if (nGearDir[i] == -1) // 반시계
		{
			
			int first = vGear[i][0];
			for (int j = 0; j < vGear[i].size()-1; j++)
			{
				vGear[i][j] = vGear[i][j + 1];
			}
			vGear[i][7] = first;
		}
	}

	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 4; i++) //vGear->size() : vGear 배열의 첫 번째 원소(vGear[0])의 size()”
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
		RotateGear(gearIdx - 1, gearDir);
	}

	int totalSum = 0;
	if (vGear[0][0] == 1) totalSum += 1;
	if (vGear[1][0] == 1) totalSum += 2;
	if (vGear[2][0] == 1) totalSum += 4;
	if (vGear[3][0] == 1) totalSum += 8;

	cout << totalSum;
	return 0;
}