#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int a[11][11] = { 0 };
	int n, col = 1, row = 1;
	cin >> n;
	vector<int> front(n + 1);
	vector<int> rightward(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> front[i];
	}

	for (int i = n; i >= 1; i--)
	{
		cin >> rightward[i];
	}

	//col fix
	for (col = 1; col <= n; col++)
	{
		for (row = n; row >= 1; row--)
		{
			a[row][col] = front[col];
		}
	}

	//row fix
	for (row = 1; row <= n; row++)
	{
		for (col = 1; col <= n; col++)
		{
			if (a[row][col] > rightward[row])
			{
				a[row][col] = rightward[row];
			}
		}
	}

	int sum = 0;

	for (col = 1; col <= n; col++)
	{
		for (row = 1; row <= n; row++)
		{
			sum += a[row][col];
		}
	}

	cout << sum;

	return 0;
}
