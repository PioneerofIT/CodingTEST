#include <iostream>

using namespace std;

long long n;
int arrExamArea[1000001];
long long canSawMain, canSawSub;

long long sumTotal = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;

	for (long long i = 1; i <= n; i++)
	{
		cin >> arrExamArea[i];
	}

	cin >> canSawMain >> canSawSub;

	for (long long j = 1; j <= n; j++)
	{
		long long remainStudent = arrExamArea[j] - canSawMain; // 오직 1명만 있어야한다.
		sumTotal++;

		while (remainStudent >= 0)
		{
			if ((remainStudent / canSawSub) != 0)
			{
				remainStudent -= canSawSub;
				sumTotal++;
			}
			else if ((remainStudent / canSawSub) == 0 && (remainStudent % canSawSub) != 0)
			{
				remainStudent -= canSawSub;
				sumTotal++;
			}
		}

	}


	cout << sumTotal;

	return 0;
}