#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 최선의 등수 구하기
// 나보다 실력이 좋으면 앞지르는 것은 불가능 하지만 그 반대의 경우는 가능
// 더 큰 값이 더 좋은 실력 
int main(int argc, char** argv)
{
	int N; // 인원 수
	cin >> N;
	vector<int> Data(N);
	vector<int> BestData(N);
	int BestGrade = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> Data[i];
	}  // 인덱스 순서대로 현재 등수와 데이터 값은 실력 수치

	for (int i = 0; i < Data.size(); i++)
	{
		BestGrade = (i + 1); // 처음 자기 등수 저장 

		if (i == 0)
		{
			BestData[i] = 1;
			continue;
		}

		for (int j = i-1;  j >= 0; j--)
		{
			if (Data[j] < Data[i])
			{
				BestGrade--; // 바로 출력해줘도 된다. 
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
