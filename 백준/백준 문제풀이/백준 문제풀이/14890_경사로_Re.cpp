#include <iostream>
#include <vector>
using namespace std;

int arrMap[100][100];
int N, L;
int cntRoad = 0;

bool CanPassBy(vector<int> line)
{
	bool used[100] = { false };
	for (int i = 0; i < line.size()-1; i++)
	{
		if (line[i] == line[i + 1]) continue;

		int temp = abs(line[i] - line[i + 1]);
		if (temp > 1) return false;

		// 奴 版快
		if (line[i] < line[i + 1]) 
		{
			for (int j = 0; j < L; j++)
			{
				int idx = i - j;
				if (idx < 0) return false;
				if (line[i] != line[idx]) return false;
				if (used[idx]) return false;
				used[idx] = true;
			}

		}

		if (line[i] > line[i + 1])
		{
			for (int j = 0; j < L; j++)
			{
				int idx = (i +1) + j;
				if (idx > N ) return false;
				if (line[i + 1] != line[idx]) return false;
				if (used[idx]) return false;
				used[idx] = true;
				
			}
		}
	}

	return true;
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> vLine;
	
	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arrMap[i][j];
		}
	}


	for (int i = 0; i < N; i++) // 青 贸府
	{
		for (int j = 0; j < N; j++)
		{
			vLine.push_back(arrMap[i][j]);
		}

		if (CanPassBy(vLine))
		{
			cntRoad++;
		}
		vLine.clear();
	}

	for (int j = 0; j < N; j++) // 凯 贸府
	{
		for (int i = 0; i < N; i++)
		{
			vLine.push_back(arrMap[i][j]);
		
		}

		if (CanPassBy(vLine))
		{
			cntRoad++;
		}
		vLine.clear();
	}

	cout << cntRoad;
	return 0;

}