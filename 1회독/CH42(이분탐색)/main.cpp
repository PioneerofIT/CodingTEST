#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main(int argc, char** argv) 
{
	int n, target;
	int mid;
	
	cin >> n >> target;
	
	int lt = 0, rt = n-1;
	vector<int> a(n);
	
	for(int i=0; i<n; i++)
	{
		cin >> a[i];
	}
	
	sort(a.begin(), a.end());
	
	while(1)
	{
		mid = (lt+rt) / 2;
		
		if(a[mid] < target) lt = mid + 1;
		else if (a[mid] > target ) rt = mid -1;
		else break; 
	}
	
	cout << mid+1;
	
		
	return 0;
}
