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
	if(L == n+1)
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
					DFS(L+1, arrayNum[L]+sum );
					operNum[i] ++;		
				}
				else if( i == 2)
				{
					operNum[i] --;
					DFS(L+1, arrayNum[L]-sum );
					operNum[i] ++;						
				}
				else if( i == 3)
				{
					operNum[i] --;
					DFS(L+1, arrayNum[L]*sum );
					operNum[i] ++;					
				}
				else if( i == 4)
				{
					operNum[i] --;
					DFS(L+1, sum /arrayNum[L] );
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
	
	for(int i=1; i<=4; i++)
	{
		int x;
		cin >> x;
		operNum.push_back(x);
	}
	
	DFS(2, arrayNum[1]); // 1번 인덱스 숫자는 sum에 선 누적 시키고 2번 인덱스 숫자부터 카운트 
	
	cout << maxRes << endl;
	cout << minRes << endl;
	
	
	return 0;
}
