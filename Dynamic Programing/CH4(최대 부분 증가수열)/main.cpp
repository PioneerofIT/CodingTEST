#include <iostream>
#include <algorithm>

using namespace std;
int n;
int arr[1001];
int dy[1001];

int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	int maxRes = -2147000000;
	
	for(int i=1; i<=n; i++)
	{
		cin >> arr[i];
	}
	
	dy[1] = 1;
	for(int i=2; i<=n; i++)
	{
		dy[i] = 1;
		for(int j=i-1; j>=1; j--)
		{
			if(arr[i] > arr[j])
			{
				dy[i] = max(dy[i], dy[j]+1);
			}
		}
		maxRes = max(maxRes, dy[i]);
	}
	
	cout << maxRes;
	
	
	return 0;
}
