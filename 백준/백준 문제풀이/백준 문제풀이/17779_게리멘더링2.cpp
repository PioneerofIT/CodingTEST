#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
int answer = INT_MAX;
int arrPersonMap[101][101];
int arrBoatMap[101][101];
int N;
void CountMinMax()
{
	int arrCnt[6];
	int maxCnt = INT_MIN;
	int minCnt = INT_MAX;
	memset(arrCnt, 0, sizeof(arrCnt));
	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= N; c++)
		{
			if (arrBoatMap[r][c] == 0) return;
			arrCnt[arrBoatMap[r][c]] += arrPersonMap[r][c];
		}
	}

	for (int i = 1; i <= 5; i++)
	{
		maxCnt = max(maxCnt, arrCnt[i]);
		minCnt = min(minCnt, arrCnt[i]);
	}
	answer = min(answer, maxCnt - minCnt);
}
void FillBoatArea(int x, int y, int d1, int d2)
{
	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= N; c++)
		{
			if (arrBoatMap[r][c] == 5) continue;

			if (r < x + d1 && c <= y) arrBoatMap[r][c] = 1;
			else if (r <= x + d2 && c > y) arrBoatMap[r][c] = 2;
			else if (r >= x + d1 && c < y - d1 + d2) arrBoatMap[r][c] = 3;
			else if (r > x + d2 && c >= y - d1 + d2) arrBoatMap[r][c] = 4;
			
		
		}
	}
	
	CountMinMax();
}
void Calc(int x, int y, int d1, int d2)
{
	int sum[6] = { 0 };

	// 5번
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (arrBoatMap[r][c] == 5)
				sum[5] += arrPersonMap[r][c];
		}
	}

	// 1번
	for (int r = 1; r < x + d1; r++) {
		for (int c = 1; c <= y; c++) {
			if (arrBoatMap[r][c] != 5)
				sum[1] += arrPersonMap[r][c];
		}
	}

	// 2번
	for (int r = 1; r <= x + d2; r++) {
		for (int c = y + 1; c <= N; c++) {
			if (arrBoatMap[r][c] != 5)
				sum[2] += arrPersonMap[r][c];
		}
	}

	// 3번
	for (int r = x + d1; r <= N; r++) {
		for (int c = 1; c < y - d1 + d2; c++) {
			if (arrBoatMap[r][c] != 5)
				sum[3] += arrPersonMap[r][c];
		}
	}

	// 4번 = 전체 - (1+2+3+5)
	int total = 0;
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
			total += arrPersonMap[r][c];

	sum[4] = total - (sum[1] + sum[2] + sum[3] + sum[5]);

	int mx = *max_element(sum + 1, sum + 6);
	int mn = *min_element(sum + 1, sum + 6);
	answer = min(answer, mx - mn);
}

									
void FillBoundLine(int x, int y, int d1, int d2)
{
	memset(arrBoatMap, 0, sizeof(arrBoatMap));
	//1번
	for (int tmp = 0; tmp <= d1; tmp++)
	{
		arrBoatMap[x + tmp][y - tmp] = 5;
	}
	//2번
	for (int tmp = 0; tmp <= d2; tmp++)
	{
		arrBoatMap[x + tmp][y + tmp] = 5;
	}
	//3번
	for (int tmp = 0; tmp <= d2; tmp++)
	{
		arrBoatMap[x +d1+ tmp][y-d1 + tmp] = 5;
	}
	//4번
	for (int tmp = 0; tmp <= d1; tmp++)
	{
		arrBoatMap[x + d2 + tmp][y + d2 - tmp] = 5;
	}

	//내부 5번 채우기
	for (int row = x + 1; row < x + d1 + d2; row++)
	{
		bool inside = false;
		for (int col = 1; col <= N; col++)   // ★ 1~N 전체
		{
			if (arrBoatMap[row][col] == 5) inside = !inside;
			if (inside) arrBoatMap[row][col] = 5;
		}
	}
	
	//FillBoatArea(x, y, d1, d2);
	Calc(x, y, d1, d2);

}




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arrPersonMap[i][j];
		}
	}

	for (int x = 1; x <= N; x++)
	{
		for (int y = 1; y <= N; y++)
		{
			for (int d1 = 1; d1 <= N; d1++)
			{
				for (int d2 = 1; d2 <= N; d2++)
				{

					if (x + d1 + d2 > N ) continue;
					if (y - d1 < 1) continue;
					if (y + d2 > N) continue;

					FillBoundLine(x, y, d1, d2);
					


				}
			}
		}
	}
	cout << answer;

	return 0;
}