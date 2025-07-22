#include <iostream>
#include <vector>
using namespace std; 

int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	
	int n, idx;
	cin >> n;
	vector<int> SelSort(n, 0);
	vector<int> temp(n, 0);
	
	for(int i=0; i<n; i++)
	{
		cin >> SelSort[i];
	}
	
	for(int i=0; i<SelSort.size()-1; i++)
	{
		idx = i;
		for(int j=i+1; j<n; j++)
		{
			if(SelSort[idx] > SelSort[j]) // DESC는 부호 반대로 
			{
				idx = j;
			}
		}
	
	temp[i] = SelSort[i];
	SelSort[i] = SelSort[idx];
	SelSort[idx] = temp[i];	
		
	}
	
	for(int i=0; i<SelSort.size(); i++)
	{
		cout << SelSort[i] << " ";
	}
	return 0;
}
