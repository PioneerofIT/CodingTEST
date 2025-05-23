#include <iostream>
#include <vector>
using namespace std;

int n;
int minRes = 2147000000;
int maxRes = -2147000000;
vector<int> arrayNum;
vector<int> operNum;

void DFS(int L, int sum)
{
	if(L == n)
	{
		if(sum < minRes )
		{
			minRes = sum;		
		}
		
		if(sum > maxRes )
		{
			maxRes = sum;	
		}
	}
	else
	{
		for(int i=1; i<=4; i++)
		{
			if(operNum[i] != 0)
			{
				if( i == 1)
				{
					operNum[i] --;
					DFS(L+1, arrayNum[i]+sum );
					operNum[i] ++;		
				}
				else if( i == 2)
				{
					operNum[i] --;
					DFS(L+1, arrayNum[i]-sum );
					operNum[i] ++;						
				}
				else if( i == 3)
				{
					operNum[i] --;
					DFS(L+1, arrayNum[i]*sum );
					operNum[i] ++;					
				}
				else if( i == 4)
				{
					operNum[i] --;
					DFS(L+1, arrayNum[i]/sum );
					operNum[i] ++;						
				}
					
			
			}		
		}	
	}
	
}
int main(int argc, char** argv) 
{
	cin >> n;
	
	arrayNum.push_back(0);
	operNum.push_back(0);
	
	for(int i=0; i<n; i++)
	{
		int x;
		cin >> x;
		
		arrayNum.push_back(x);
	}
	
	for(int i=0; i<n-1; i++)
	{
		int x;
		cin >> x;
		operNum.push_back(x);
	}
	
	DFS(1,0);
	
	cout << maxRes << endl;
	cout << minRes << endl;
	
	
	return 0;
}
