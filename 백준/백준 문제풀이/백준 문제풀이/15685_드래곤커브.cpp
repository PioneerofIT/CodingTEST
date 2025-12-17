#include <iostream>
#include <vector>
using namespace std;

int n;
int arrMap[101][101];
int dr[4] = { 0, -1, 0, 1 };
int dc[4] = { 1, 0, -1, 0 };
int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> vDirSet;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x, y, d, g;

		cin >> x >> y >> d >> g;
		vDirSet.clear();

		arrMap[y][x] = 1;
		vDirSet.push_back(d);

		for (int j = 0; j < g; j++) // 0세대는 초기에 진행
		{
			for (int z = vDirSet.size()-1; z >=0 ; z--)
			{
				vDirSet.push_back((vDirSet[z] + 1) % 4);
			}
		}

		for (int k = 0; k < vDirSet.size(); k++)
		{
			 y += dr[vDirSet[k]];
			 x += dc[vDirSet[k]];

			if (y >= 0 && y <= 100 && x >= 0 && x <=100)
				arrMap[y][x] = 1;
		}


	}

	int countSqure = 0;

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (arrMap[i][j] == 1 && arrMap[i][j + 1] ==1&& arrMap[i + 1][j] == 1 && arrMap[i + 1][j + 1] == 1)
			{
				countSqure++;
			}
		}
	}
	cout << countSqure;
	return 0;
}