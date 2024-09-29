#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) 
{
	
	int N;
	cin >> N;
	int cnt = 0;
	
	for(int i=1; i<=N; i++)
	{
		int tmp = i;
		int share;
		while(1)
		{
			share = (tmp % 10);
			if(share == 3) cnt++;
			
			tmp /= 10;
			
			if(tmp == 0) break; 
		}
	}
	
	cout << cnt;
	return 0;
}
