#include <iostream>
#include <vector>

using namespace std;
int n, l;
int roadCnt;
int arrMap[100][100];

bool CheckRoad(vector<int> line)
{
	//..Ex :[ 2 2 2 3 2 3]

	bool used[100] = { false };

	for (int i = 0; i < n-1; i++)
	{
		if (line[i] == line[i + 1]) continue;

		if (abs(line[i] - line[i + 1]) > 1) return false;
		
		//오르막
		if (line[i] + 1 == line[i + 1])
		{
			int h = line[i];

			if (i - (l - 1) < 0) return false; // 인덱스 확인 오르막 길이 l 만큼

			for (int j = i; j > i - l; j--)
			{
				if (line[j] != h) return false;
				if (used[j]) return false;

				used[j] = true;
			}

		}

		//내리막
		if (line[i] - 1 == line[i + 1])
		{
			int h = line[i+1];

			if (i+l >= n) return false;

			for (int j = i+1; j <= i + l; j++)
			{
				if (line[j] != h) return false;
				if (used[j]) return false;

				used[j] = true;
			}

		}
	}

	return true;
}

int main()
{

	cin >> n >> l;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arrMap[i][j];
		}
	}

	// Check Row
	for (int i = 0; i < n; i++)
	{
		vector<int> line;
		for (int j = 0; j < n; j++)
		{
			line.push_back(arrMap[i][j]);
		}
		if (CheckRoad(line)) roadCnt++;
	}


	// Check Col
	for (int i = 0; i < n; i++)
	{
		vector<int> line;
		for (int j = 0; j < n; j++)
		{
			line.push_back(arrMap[j][i]);
		}
		if (CheckRoad(line)) roadCnt++;
	}

	cout << roadCnt;

	return 0;
}