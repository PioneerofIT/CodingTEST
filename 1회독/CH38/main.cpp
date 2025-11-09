#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char** argv) 
{
	int n;
	cin >> n;
	
	vector<int> is(n+1);
	vector<int> os(n+1);
	int temp,pos;
	
	for(int i=1; i<=n; i++)
	{
		cin >> is[i];
	}
	
	for(int i=n; i>=1; i--)
	{
		os[i] = i;
		pos = i;
		for(int j=is[i]; j>0; j--)
		{
			temp = os[pos];
			os[pos] = os[pos+1];
			os[pos+1] = temp;
			pos++;
			
		}
	}
	
	for(int i=1; i<=n; i++)
	{
		cout << os[i] << " ";
	}
	
	return 0;
}
