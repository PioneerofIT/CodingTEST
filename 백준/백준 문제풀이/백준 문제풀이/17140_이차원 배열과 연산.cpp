#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <queue>
#include <climits>
using namespace std;

struct Node
{
	int index;
	int count;

	Node(int index, int count)
	{
		this->index = index;
		this->count = count;
	}
	
	//¿Ã∞‘ «ŸΩ… !
	bool operator<(const Node& arg)
	{
		if (count != arg.count) return count < arg.count;
		if (index != arg.index) return index < arg.index;
	}
};
int r, c, k;
int arrMap[101][101];
int timer = 0;
int maxRow = 3;
int maxCol = 3;
bool CheckValue()
{
	if (arrMap[r][c] == k)
	{
		return true;
	}
	else
	{
		return false;
	}
}

vector<int> SortLine(vector<int> line)
{
	int tempArr[101];
	memset(tempArr, 0, sizeof(tempArr));

	
	int maxIdx = INT_MIN;
	for (int i = 0; i < line.size(); i++)
	{
		
		if (line[i] == 0) continue;

		//[3,1,1] : ºˆ
		tempArr[line[i]]++;
		if (maxIdx < line[i])
		{
			maxIdx = line[i];
		}

	}

	vector<Node> sortVector;
	sortVector.clear();

	for (int i = 1; i <= maxIdx; i++)
	{
		if (tempArr[i] != 0)
		{
			sortVector.push_back(Node(i, tempArr[i]));
		}
	}
	sort(sortVector.begin(), sortVector.end());

	vector<int> lineVec;
	lineVec.clear();
	for (int i = 0; i < sortVector.size(); i++)
	{
		Node node = sortVector[i];
		lineVec.push_back(node.index);
		lineVec.push_back(node.count);
	}

	return lineVec;

}

void SortArr()
{
	
	vector<int> line;
	line.clear();
	int tempArr[101][101];
	memset(tempArr, 0, sizeof(tempArr));

	if (maxRow >= maxCol)
	{
		for (int row = 1; row<= maxRow; row++)
		{
			line.clear();
			for (int col = 1; col <= maxCol; col++)
			{
				line.push_back(arrMap[row][col]); // [3,1,1]
			}
			
			vector<int> sortVec = SortLine(line);

			for (int i = 0; i < sortVec.size(); i++)
			{
				tempArr[row][i+1] = sortVec[i];
			}
			maxCol = max(maxCol, (int)sortVec.size());


		}
	}
	else
	{
		for (int col = 1; col <= maxCol; col++)
		{
			line.clear(); 
			for (int row = 1; row <= maxRow; row++)
			{
				line.push_back(arrMap[row][col]);
			}

			vector<int> sortVec = SortLine(line);

			for (int i = 0; i < sortVec.size(); i++)
			{
				tempArr[i+1][col] = sortVec[i];
			}
			maxRow = max(maxRow, (int)sortVec.size());
	
		}
	}

	memcpy(arrMap, tempArr, sizeof(tempArr));

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> r >> c >> k;

	//init
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cin >> arrMap[i][j];
		}
	}

	while (true)
	{
		if (CheckValue())
		{
			cout << timer;
			return 0;
		}
		else if (timer > 100)
		{
			cout << -1;
			return 0;
		}

		timer++;
		SortArr();
	}


	return 0;
}