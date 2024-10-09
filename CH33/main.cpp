#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) 
{
	
	int n;
	cin >> n;
	vector<int> data(n);
	int idx;
	int temp;
	int cnt = 1;
	
	for(int i=0; i<n; i++)
	{
		cin >> data[i];
	}
	
	for(int i=0; i<n-1; i++)
	{
		idx = i;
		for(int j=i+1; j<n; j++)
		{
			if(data[j] > data[idx])
			{
				idx = j;	
			}	
		}
		temp = data[i];
		data[i] = data[idx];
		data[idx] = temp;	
	}
	
	for(int i=1; i<data.size(); i++)
	{
		if(data[i-1] > data[i] ) 
		{
			cnt ++;
		}
		
		if(cnt == 3)
		{
			cout << data[i];
			break;
		}
	}
	return 0;
}
