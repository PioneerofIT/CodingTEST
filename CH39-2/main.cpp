#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
	int n, m;
	
	cin >> n;
	
	vector<int> a(n);
	for(int i=0; i<n; i++)
	{
		cin >> a[i];
	}
	// ===========================
	cin>>m;
	vector<int> b(m);
	for(int i=0; i<m; i++)
	{
		cin >> b[i];
	}
	
	vector<int> c(n+m);
	
	int pos1=0, pos2=0, pos3=0;
	 
	while(pos1 != n || pos2 != m)
	{
		if(a[pos1] < b[pos2] )
		{
			c[pos3]  = a[pos1];
			pos1++;
			pos3++;
		}
		else if( a[pos1] > b[pos2])
		{
			c[pos3] = b[pos2];
			pos2 ++;
			pos3 ++;
		}
		else if( a[pos1] == b[pos2]) 
		{
			c[pos3] = a[pos1];
			pos1++;
			pos2++;
			pos3++;
		}
	}
	
	if(pos1 == n)
	{
		for()
	}
	
	
	
	return 0;
}
