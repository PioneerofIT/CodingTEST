#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 일의 자리의 '0'이 붙는건 10이 곱해지는 경우 이므로 모든 인수를 소인수분해하여 2,5의 쌍 값을 구하여 가장 작은 인수의 값을 출력 
int main(int argc, char** argv) 
{
	int N;
	cin >> N;
	
	int Cnt2,Cnt5 =0;
	int j;
	int tmp;
	
	for(int i=2; i<=N; i++)
	{
		j=2;
		tmp = i;
		
		while(1)
		{
			if( tmp % j == 0)
			{
				if(j == 2) Cnt2 ++;
				else if(j == 5) Cnt5++;
				tmp /= j;					
			}
			else j++;
			
			if(tmp == 1) break;
			
		}
		
	}
	
	if(Cnt2 < Cnt5) cout << Cnt2;
	else cout << Cnt5;
	
	return 0;
}
