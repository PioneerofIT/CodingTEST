#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//선택 정렬
int main(int argc, char** argv) 
{
	
	int N;
	cin >> N;
	vector<int> Num(N);
	int idx;
	int temp;
	
	
	for(int i=0; i<N; i++)
	{
		cin >> Num[i];
	}
	
	for(int i=0; i<N-1; i++)
	{
		idx = i;
		for(int j=i+1; j<N; j++)
		{
			if(Num[j] < Num[idx] )
			{
				idx = j;
			}
		}
		temp = Num[i];
		Num[i] = Num[idx];
		Num[idx] = temp;
	}
	
	for(int i=0; i<Num.size(); i++)
	{
		cout << Num[i] <<" ";	
	}
	return 0;
}
