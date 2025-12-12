#include <iostream>
#include <vector>
#include<climits>
using namespace std;

int n;
int arrMap[20][20];
bool visited[20];
int minNum = INT_MAX;

void CalTeam(vector<int> team1, vector<int> team2)
{
	int team1Sum = 0;
	for (int i = 0; i < team1.size(); i++)
	{
		for (int j = i + 1; j < team1.size(); j++)
		{
			int x = team1[i];
			int y = team1[j];

			team1Sum += arrMap[x][y] + arrMap[y][x];

		}
	}

	int team2Sum = 0;
	for (int i = 0; i < team2.size(); i++)
	{
		for (int j = i + 1; j < team2.size(); j++)
		{
			int x = team2[i];
			int y = team2[j];

			team2Sum += arrMap[x][y] + arrMap[y][x];

		}
	}
	minNum = min(minNum, abs(team1Sum - team2Sum));

}

void Dfs(int L, int startIdx)
{
	if (L ==  n / 2)
	{
		vector<int> team1;
		vector<int> team2;
		for (int i = 0; i < n; i++)
		{
			if (visited[i])
			{
				team1.push_back(i);
			}
			else
			{
				team2.push_back(i);
			}
		}
		CalTeam(team1, team2);

	}
	else
	{
		for (int i = startIdx; i < n; i++)
		{
			if (!visited[i])
			{
				visited[i] = true;
				Dfs(L + 1, i + 1);
				visited[i] = false;
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
			cin >> arrMap[i][j];
		}
	}

	Dfs(0,0);

	cout << minNum;
	return 0;
}