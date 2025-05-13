#include <iostream>

using namespace std;

int n;
int target;
int total = 0;
int a[101];

void DFS(int L, int sum)
{
	if(L == n+1)
	{
		if(sum == target)
		{
			total ++;
		}
		
		return;
	}
	else
	{
		DFS(L+1, sum+a[L]);
		DFS(L+1, sum-a[L]);
		DFS(L+1, sum);
	}
	
}

int main(int argc, char** argv) 
{
	cin >> n >> target;
	
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	
	DFS(1, 0);
	
	if(total > 0)
	{
		cout << total;
	}
	else
	{
		cout << "-1";
	}
	return 0;
}
