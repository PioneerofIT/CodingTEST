#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {

	int n;
	cin >> n;
	vector<int> a(n);
	int idx;
	int temp;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n ; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1]) // ������ �� �� ���� ���� ���� ã�� 
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}

	}

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}


	return 0;
}
