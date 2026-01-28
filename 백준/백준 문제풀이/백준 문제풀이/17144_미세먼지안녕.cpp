#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dr[4] = { 0, -1, 0, 1 };
int dc[4] = { 1, 0, -1, 0 };
int arrMap[50][50];
int r, c, t = 0;
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
			if (arrMap[i][j] > 0)
			{
				int spreadDust = (arrMap[i][j] / 5);
				int spreadCnt = 0;

				for (int z = 0; z < 4; z++)
				{
					int nx = i + dr[z];
					int ny = j + dc[z];

					if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
					if (arrMap[nx][ny] == -1) continue;

					// 瘤加 穿利
					tempArr[nx][ny] += spreadDust;
					spreadCnt++;
				}

				tempArr[i][j] += arrMap[i][j] - ( spreadDust * spreadCnt);
			}
		}
	}

	memcpy(arrMap, tempArr, sizeof(tempArr));
}

void Clean()
{
	//Cw
	//备埃 1
	for (int row = topRow - 1; row > 0; row--)
	{
		arrMap[row][0] = arrMap[row - 1][0];
	}
	//备埃 2
	for (int col = 0; col < c-1; col++)
	{
		arrMap[0][col] = arrMap[0][col + 1];
	}
	//备埃 3
	for (int row = 0; row < topRow; row++)
	{
		arrMap[row][c-1] = arrMap[row + 1][c-1];

	}
	//备埃 4
	for (int col = c - 1; col > 1; col--)
	{
		arrMap[topRow][col] = arrMap[topRow][col - 1];
	}
	arrMap[topRow][1] = 0;
	

	//Ccw
	//备埃 1
	for (int row = botRow+1; row < r - 1; row++)
	{
		arrMap[row][0] = arrMap[row + 1][0];
	}
	//备埃 2
	for (int col = 0; col < c - 1; col++)
	{
		arrMap[r-1][col] = arrMap[r-1][col + 1];
	}
	//备埃 3
	for (int row = (r-1); row > botRow-1; row--)
	{
		arrMap[row][c-1] = arrMap[row-1][c-1];
	}
	//备埃 4
	for (int col = c-1; col > 1; col--)
	{
		arrMap[botRow][col] = arrMap[botRow][col - 1];
	}
	arrMap[botRow][1] = 0;


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