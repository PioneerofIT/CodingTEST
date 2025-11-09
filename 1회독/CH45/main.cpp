#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int n, k; // n : 왕자 수 k : 외치면 제외 되는 번호

	cin >> n >> k;

	vector<int> a(n + 1);

	int cnt;
	int pos = 0;
	int res;

	while (1)
	{
		cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == 1)
			{
				cnt++;
			}
			else
			{
				res = i;
			}
		}

		if (cnt == (a.size() - 1))
			break;

		for (int i = k; i > 0; i--)
		{
			pos++;

			if (pos == n)
			{
				pos = 1;
			}
		}
		a[pos] = 1;
	}

	cout << res;
	return 0;
}
