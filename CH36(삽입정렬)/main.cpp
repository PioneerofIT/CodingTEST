#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//삽입정렬 오름차순 
int main(int argc, char** argv) 
{
	int n;
	cin >> n;
	vector<int> a(n); 
	int temp;
	int i,j;
	
	for(int i=0; i<n; i++)
	{
		cin >> a[i];
	}
	
	for(i=1; i<n; i++)
	{
		temp = a[i];
		for(j=i-1; j>=0; j--)
		{
			if( a[j] > temp)
			{
				a[j+1] = a[j]; 
			}
			else
				break;
		}
		a[j+1] = temp;
	}
	
	for(i=0; i<a.size(); i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}
