#include <iostream>
#include <climits>

using namespace std;

int maxVal = INT_MIN;
int minVal = INT_MAX;

int arrNum[11];
int arrOper[5];
int n;
int sum =0;

void DFS(int L, int sum)
{
	if(L == n)
	{
		if(sum < minVal)
		{
			minVal = sum;
		}
		
		if(sum > maxVal)
		{
			maxVal = sum;
		}
		return;
	}
	else
	{
		if(arrOper[1] != 0 )
		{
			arrOper[1] --;
			DFS(L+1, sum+arrNum[L+1]);
			arrOper[1] ++;
			
		}
		
		if(arrOper[2] != 0 )
		{
			arrOper[2] --;
			DFS(L+1, sum-arrNum[L+1]);
			arrOper[2] ++;
		}
		
		if(arrOper[3] != 0 )
		{
			arrOper[3] --;
			DFS(L+1, sum*arrNum[L+1]);
			arrOper[3] ++; 
		}
		if(arrOper[4] != 0 )
		{
			arrOper[4] --;
			DFS(L+1, sum/arrNum[L+1]);
			arrOper[4] ++;
		}
		
	}
}


int main(int argc, char** argv) 
{
	
	cin >> n;
	
	for(int i=1; i<=n; i++)
	{
		cin >> arrNum[i];
	}
	
	for(int i=1; i<=4; i++)
	{
		cin >> arrOper[i];
	}
	
	DFS(1,arrNum[1]);
	cout << maxVal << endl;
	cout << minVal << endl;
	
	return 0;
}
