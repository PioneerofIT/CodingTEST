#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// ���� �ڸ��� '0'�� �ٴ°� 10�� �������� ��� �̹Ƿ� ��� �μ��� ���μ������Ͽ� 2,5�� �� ���� ���Ͽ� ���� ���� �μ��� ���� ��� 
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
