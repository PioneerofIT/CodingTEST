#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dr[4] = { 0, -1, 0, 1 };
int dc[4] = { 1, 0, -1, 0 };
int arrMap[50][50];
int r, c, t;
int topRow;
int botRow;

void Spread()
{
	int tempArr[50][50];
	memset(tempArr, 0, sizeof(tempArr));

	tempArr[topRow][0] = -1;
	tempArr[botRow][0] = -1;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (arrMap[i][j] != -1 && arrMap[i][j] != 0)
			{

			}
		}
	}

}

void Clean()
{

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> r >> c >> t;
	
	bool isChecked = false;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> arrMap[i][j];

			if (arrMap[i][j] == -1 && !isChecked)
			{
				isChecked = true;
				topRow = i;
				botRow = i + 1;
			}
		}
	}

	while (t > 0)
	{
		Spread();
		Clean();

		t--;
	}

	int sumDust = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (i == topRow && j == 0) continue;
			else if (i == botRow && j == 0) continue;

			sumDust += arrMap[i][j];
		}
	}
	cout << sumDust;
	return 0;
}