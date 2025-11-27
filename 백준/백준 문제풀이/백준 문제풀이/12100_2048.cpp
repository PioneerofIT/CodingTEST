#include <iostream>
#include <vector>
#include <climits>
#include<algorithm>
#include <cstring>
#include <stdio.h>
using namespace std;

int boardMap[20][20];
int n;
bool visited[5][5]; // 해당 레벨에서 그 dir을 방문했는지
int numMax = INT_MIN;

vector<int> ProcessLine(vector<int> line)
{
	vector<int> temp;

	// 0로 압축
	for (int i = 0; i < (int)line.size(); i++)
	{
		if (line[i] != 0)
		{
			temp.push_back(line[i]);
		}
	}

	for (int j = 0; j  < (int)temp.size()-1; j++)
	{
		if (temp[j] == temp[j + 1]) // Ex. [ 2, 2, 3, 4 ] -> [ 4, 0 , 3 , 4 ]  
		{
			temp[j] = temp[j] * 2;
			temp[j + 1] = 0;
			j++; // 합쳐진 인덱스 스킵 for문 나가면 한번 더 j++을 하니께...
		}
	}

	vector<int> compressedLine;
	for (int i = 0; i < (int)temp.size(); i++)
	{
		if (temp[i] != 0)
		{
			compressedLine.push_back(temp[i]);
		}
	}
	
	compressedLine.resize(n, 0); // [ 4, 3, 4 , 0]

	return compressedLine;
	
}

void MoveLine(int dir)
{
	vector<int> line;

	if (dir == 0) // Up : col -> row 순
	{
		
		for (int col = 0; col < n; col++)
		{
			vector<int> tmpline;
			for (int row = 0; row < n; row++)
			{
				tmpline.push_back(boardMap[row][col]);
			}

			line = ProcessLine(tmpline);

			for (int row = 0; row < n; row++)
			{
				boardMap[row][col] = line[row];
			}
		
		}
		
		return;
		
		
	}
	else if (dir == 1) // Right(->) : row(n) -> col(n) start
	{ 
		
		for (int row = (n - 1); row >= 0; row--)
		{
			vector<int> tmpline;
			for (int col = (n - 1); col >= 0; col--)
			{
				tmpline.push_back(boardMap[row][col]);
			}
			line = ProcessLine(tmpline);

			for (int col = 0; col < n; col++)
			{
				boardMap[row][col] = line[n - 1 - col];
			}
		}
	}
	else if (dir == 2) // Down : col(0) -> row(n-1)
	{
		for (int col = 0; col < n; col++)
		{
			vector<int> tmpline;
			for (int row = (n - 1); row >= 0; row--)
			{
				tmpline.push_back(boardMap[row][col]);
			}
			line = ProcessLine(tmpline);

			for (int row = (n - 1); row >= 0; row--)
			{
				boardMap[row][col] = line[n-1-row];
			}
		}
	}
	else if (dir == 3) // Left(<-) : row(0) col(0)
	{
		for (int row = 0; row <n; row++)
		{
			vector<int> tmpline;
			for (int col=0; col<n; col++)
			{
				tmpline.push_back(boardMap[row][col]);
			}
			line = ProcessLine(tmpline);

			for (int col = 0; col<n; col++)
			{
				boardMap[row][col] = line[col];
			}
		}
	}
}

void DFS(int L)
{
	if (L == 5)
	{
		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < n; col++)
			{
				if (boardMap[row][col] > numMax)
				{
					numMax = boardMap[row][col];
				}
			}
		}

		return;
	}
	else
	{
		for (int dir = 0; dir < 4; dir++)
		{
			if (!visited[L][dir])
			{
				int backup[20][20];
				memcpy(backup, boardMap, sizeof(boardMap));
				visited[L][dir] = true;
				MoveLine(dir);
				DFS(L + 1);
				visited[L][dir] = false;
				memcpy(boardMap, backup, sizeof(backup));
			}
		}
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> boardMap[i][j];
		}
	}

	DFS(0);
	cout << numMax;

	return 0;
}