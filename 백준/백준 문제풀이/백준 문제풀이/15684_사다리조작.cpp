#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int arrMap[31][11]; // 1-based
int n, m, h;
int dr[3] = { 0, 1, 0};
int dc[3] = { 1, 0 , -1 };
int minNum = INT_MAX;
int GoDown(int startIdx)
{
	//Âß ³»·Á°¡¶ó..
	int nowCol = startIdx;
	
	for (int i = 1; i <= h; i++)
	{
		if (nowCol > 1 && arrMap[i][nowCol-1] == 1)
		{
			nowCol--;
		}
		else if (nowCol < n && arrMap[i][nowCol] == 1)
		{
			nowCol++;
		}
	}

	return nowCol;
}

bool CanPlace(int row, int col)
{
	if (arrMap[row][col] == 1) return false;

	//¿ÞÂÊ¿¡ ÀÖ³ª?
	if (col > 1 && arrMap[row][col - 1] == 1) return false;

	if (col < n-1 && arrMap[row][col + 1] == 1) return false;

	return true;
}

bool CheckRoute()
{

	for (int i = 1; i <= n; i++)
	{
		if (i != GoDown(i))
		{
			return false;
		}
	}

	return true;
}

void Dfs(int cnt, int startRow)
{
	if (cnt > 3)
	{
		return;
	}


	if (CheckRoute())
	{
		minNum = min(minNum, cnt);
	}

	for (int row = startRow; row <= h; row++)
	{
		for (int col = 1; col < n; col++)
		{
			if (CanPlace(row, col))
			{
				arrMap[row][col] = 1;
				Dfs(cnt + 1, row);
				arrMap[row][col] = 0;
			}
		}
	}



	
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> h;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		arrMap[a][b] = 1;

	}

	Dfs(0,1);

	if (minNum == INT_MAX)
	{
		cout << -1;
	}
	else
	{
		cout << minNum;
	}
	


	return 0;
	
	
}