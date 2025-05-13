#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int a[11];
int total =0;
bool flag = false;


void DFS(int L, int sum)
{
	if(flag == true)
		return;
	if(L == n+1)
	{
		if(total - sum == sum)
		{
			flag = true;
			cout << L ;
		}	
	}
	else
	{
		DFS(L+1, sum+a[L]);	
		DFS(L+1, sum);
	}	
}


int main(int argc, char** argv) 
{
	cin >> n;
	
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
		total += a[i];
	}
	
	DFS(1,0);
	
	if(flag) 
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}

	return 0;
}
