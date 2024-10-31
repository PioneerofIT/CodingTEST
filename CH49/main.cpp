#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) 
{
	int a[10][10] = {0};
	int n, col=0, row=0;
	cin >> n;
	vector<int> front(n);
	vector<int> rightward(n);
	
	for(int i=0; i<front.size(); i++)
	{
		cin >> front[i];
	}
	
	for(int i=(rightward.size()-1); i>=0; i-- )
	{
		cin >> rightward[i];
	}
	
	//col fix
	for(col=0; col<n; col++)
	{
		for(row = (n-1); row>=0; row --)
		{
			a[row][col] = front[col];
		}
	}
	
	//row fix
	for(row=0; row<n; row++)
	{
		for(col=0; col<n; col++)
		{
			if( a[row][col] > rightward[row] )
			{
				a[row][col] = rightward[row];	
			}
		}
	}
	
	int cnt = 0;
	
	for(col=0; col<n; col++)
	{
		for(row = 0; row <n; row --)
		{
			cnt += a[row][col];
		}
	}
	
	cout << cnt ;
	
	return 0;
}
