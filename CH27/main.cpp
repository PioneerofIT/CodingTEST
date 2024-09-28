#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char** argv) 
{
	int N;
	std::cin >> N;
	std::vector<int> Cnt(N+1); // 1 ~ N 까지 소수의 인덱스 
	
	
	for(int i=2; i<=N; i++)
	{
		int temp = i;
		int j=2;
		
		while(1)
		{
			if(temp % j == 0)
			{
				Cnt[j] ++;
				temp /= j;	
			}
			else
			{
				j++;	
			}
			
			if(temp == 1) break;	
		}	
	}
	std::cout << N <<"! = ";
	for(int i=0; i<Cnt.size(); i++)
	{
		if(Cnt[i] != 0) std::cout << Cnt[i] << " ";
	}
	
	return 0;
}

