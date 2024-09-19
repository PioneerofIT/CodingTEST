#include <iostream>
#include <vector>
using namespace std;

// �Է� : N(�µ��� ������ ��ü ��¥ ��) , K(���� ���ϱ� ���� �������� ��¥ ��) 
// ������ �����̵� �˰��� --> �ʱ� �� ��� �� ��ĭ�� �̵� 

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
	
	//�ʱ� �����콽���̵� �ʱ�ȭ 
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
