#include <iostream>
#include <vector>
using namespace std;

vector<int> T,P;
int n;
int maxval = -2147000000;

void DFS(int L, int sum)
{
	if(L == n+1)
	{
		if(sum > maxval)
		{
			maxval = sum;
		}
	}
	else
	{
		// 상담 진행을 할 경우 
		if(L+T[L] <= n+1)
		{
			DFS(L+T[L] , sum+P[L]);
		}
		else
		{
			DFS(L+1, sum);	
		}
		
	}
}


int main(int argc, char** argv) 
{
	
	cin >> n;
	
	//Index 0 제외 
	T.push_back(0);
	P.push_back(0);
	
	for(int i=0; i<n; i++)
	{
		int a, b;
		cin >> a >> b;
		
		T.push_back(a);
		P.push_back(b);		
	}
	DFS(1,0);
	
	cout << maxval;
	
	return 0;
}
