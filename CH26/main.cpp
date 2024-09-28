#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// �ּ��� ��� ���ϱ�
// ������ �Ƿ��� ������ �������� ���� �Ұ��� ������ �� �ݴ��� ���� ����
// �� ū ���� �� ���� �Ƿ� 
int main(int argc, char** argv)
{
	int N; // �ο� ��
	cin >> N;
	vector<int> Data(N);
	vector<int> BestData(N);
	int BestGrade = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> Data[i];
	}  // �ε��� ������� ���� ����� ������ ���� �Ƿ� ��ġ

	for (int i = 0; i < Data.size(); i++)
	{
		BestGrade = (i + 1); // ó�� �ڱ� ��� ���� 

		if (i == 0)
		{
			BestData[i] = 1;
			continue;
		}

		for (int j = i-1;  j >= 0; j--)
		{
			if (Data[j] < Data[i])
			{
				BestGrade--; // �ٷ� ������൵ �ȴ�. 
			}
		}

		BestData[i] = BestGrade;
	}

	for (int i = 0; i < BestData.size(); i++)
	{
		cout << BestData[i] << " ";
	}

	return 0;
}
