#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dr[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dc[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

int n, m, k;
int arrMap[10][10]; //양분의 수
int A[10][10];
vector<int> vTreeAge[10][10];

void SpringAndSummer()
{
	
	// 나이 어린순으로 정렬
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sort(vTreeAge[i][j].begin(), vTreeAge[i][j].end());
		}
	}

	vector<int> vAliveTree[10][10];


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int idx = 0;
			for (; idx < vTreeAge[i][j].size(); idx++)
			{
				if (arrMap[i][j] >= vTreeAge[i][j][idx])
				{
					arrMap[i][j] -= vTreeAge[i][j][idx];
					vTreeAge[i][j][idx]++;
					vAliveTree[i][j].push_back(vTreeAge[i][j][idx]);
				}
				else
				{
					break;
		
				}
			}

			for (; idx < vTreeAge[i][j].size(); idx++)
			{
				arrMap[i][j] += vTreeAge[i][j][idx] / 2;
			}


		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			vTreeAge[i][j] = vAliveTree[i][j];
		}
	}



}

void Fall()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int idx = 0; idx < vTreeAge[i][j].size(); idx++)
			{
				if (vTreeAge[i][j][idx] % 5 == 0)
				{
					for (int c = 0; c < 8; c++)
					{
						int xx = i + dr[c];
						int yy = j + dc[c];

						if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;


						vTreeAge[xx][yy].push_back(1);
						
					}
				}
			}
		}
	}
}

void Winter()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arrMap[i][j] += A[i][j];
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
			arrMap[i][j] = 5;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		vTreeAge[x-1][y-1].push_back(z);
	}

	while (k > 0)
	{
		SpringAndSummer();
		Fall();
		Winter();

		k--;
	}

	int aliveCnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			aliveCnt += vTreeAge[i][j].size();
		}
	}

	cout << aliveCnt;
	return 0;
}