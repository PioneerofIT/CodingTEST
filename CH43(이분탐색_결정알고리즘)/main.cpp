#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int n; //���� ����
	int m; // DVD ����

	cin >> n >> m;
	vector<int> t(n); //���� �ð�

	int mid, lt, rt = 0;
	vector<int> mintime;

	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
		rt += t[i];
	}
	//DVD�� �ּ� �뷮�� ���� �� ���� ���� �� �ִ� ũ�⿩�� �մϴ�.
	// ���� ���, ���� �� ���� 10��¥����� DVD�� �ּ� �뷮�� �ּ��� 10�� �̻��̾�� �մϴ�. 
	// �׷��� ������ �� �� �ϳ��� DVD�� ���� �� ������. ���� lt�� ���� �� ���� ���̷� ������, �� �� �̻����θ� Ž���� �����ϰ� ����ϴ�
	lt = *max_element(t.begin(), t.end());
	
	int result = rt;


	while (lt <= rt)
	{
		mid = (lt + rt) / 2;
		int sum = 0;
		int cnt = 1;

		for (int i = 0; i < n; i++)
		{

			if (sum+t[i] > mid)
			{
				sum = t[i];
				cnt++;
			}
			else sum += t[i];
		}

		if(cnt > m)
		{
			lt = mid + 1;
			
		}
		else
		{
			result = mid;
			rt = mid - 1;	
		}
	}
	cout << result;


	return 0;
}
