#include <iostream>
#include <vector>
using namespace std;

// 입력 : N(온도를 측정한 전체 날짜 수) , K(합을 구하기 위한 연속적인 날짜 수) 
// 윈도우 슬라이딩 알고리즘 --> 초기 값 계산 후 한칸씩 이동 

/*Time Exceed
int main(int argc, char** argv)
{
	int N;
	int K;
	int max = -217000000;
	int conNum = 0;

	cin >> N >> K;

	vector<int> Data(N);


	for (int i = 0; i < N; i++)
	{
		cin >> Data[i];
	}

	for (int i = 0; i < N-K;  i++)
	{
		for (int j = i; j < i + K; j++)
		{
			conNum += Data[j];
		}

		if (max < conNum)
			max = conNum;

		conNum = 0;
	}

	cout << max;

	return 0;
}*/

int main(int argc, char** argv)
{
	int N;
	int K;
	int maxWnd = 0;
	
	cin >> N >> K;
	
	int Data[N];
	
	for(int i=0; i < N; i++) 
	{
		cin >> Data[i];		
	}
	
	//초기 윈도우슬라이드 초기화 
	for(int i=0; i<K; i++)
	{
		maxWnd	+= Data[i];
	}
	
	int WndSlide = maxWnd;
	for(int j=K; j<N; j++)
	{
		WndSlide += Data[j] - Data[j-K];
		if(maxWnd < WndSlide) maxWnd = WndSlide; 	
	}
	
	cout << maxWnd;
	
	return 0;
	
}
