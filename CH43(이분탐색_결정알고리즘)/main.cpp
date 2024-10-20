#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int n; //곡의 갯수
	int m; // DVD 숫자

	cin >> n >> m;
	vector<int> t(n); //곡의 시간

	int mid, lt, rt = 0;
	vector<int> mintime;

	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
		rt += t[i];
	}
	//DVD의 최소 용량은 가장 긴 곡을 담을 수 있는 크기여야 합니다.
	// 예를 들어, 가장 긴 곡이 10분짜리라면 DVD의 최소 용량은 최소한 10분 이상이어야 합니다. 
	// 그렇지 않으면 그 곡 하나도 DVD에 담을 수 없겠죠. 따라서 lt를 가장 긴 곡의 길이로 설정해, 이 값 이상으로만 탐색이 가능하게 만듭니다
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
