#include <iostream>
#include <climits>
using namespace std;

int n;
int arrNum[100];
int arrOper[4];
bool visited[4];

int minNum = INT_MAX;
int maxNum = INT_MIN;

void OperDfs(int L, int sum)
{
	if (L == n-1 )
	{
		if (sum < minNum)
		{
			minNum = sum;
;		}

		if (sum > maxNum)
		{
			maxNum = sum;
		}
		return;
	}

	else
	{
		if (arrOper[0] != 0) // +
		{
			arrOper[0]--;
			OperDfs(L + 1, sum + arrNum[L + 1]);
			arrOper[0]++;
		}
		 if (arrOper[1] != 0) // -
		{
			arrOper[1]--;
			OperDfs(L + 1, sum - arrNum[L + 1]);
			arrOper[1]++;
		}
		 if (arrOper[2] != 0) // x
		{
			arrOper[2]--;
			OperDfs(L + 1, sum * arrNum[L + 1]);
			arrOper[2]++;
		}
		 if (arrOper[3] != 0)// (/)
		{
			arrOper[3]--;
			if (sum < 0) // 지금 나누려는 수가 음수면
			{
				// OperDfs(L + 1, (-1) * (( - 1)* sum / arrNum[L + 1])		); 
				
				// 좀 더 정석적으로 안전하게 ....
				int temp = abs(sum) / arrNum[L + 1];
				temp = -temp;
				OperDfs(L + 1, temp);
			}
			else
			{
				OperDfs(L + 1, sum / arrNum[L + 1]);
			}
			arrOper[3]++;
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
		cin >> arrNum[i];
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> arrOper[i];
	}

	OperDfs(0, arrNum[0]);

	cout << maxNum << endl;
	cout << minNum << endl;


	return 0;

}