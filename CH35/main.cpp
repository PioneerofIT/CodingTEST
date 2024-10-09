#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) 
{
	int n;
	cin >> n;
	vector<int> a(n);
	int temp;
	
	for(int i=0; i<n; i++)
	{
		cin >> a[i];
	}
	
	//음수 부터 다 밀면안되나
	
	 
	
	for(int i=0; i<n-1; i++)
	{
		for(int j=0; j<n-1; j++)
		{
			if(a[j] < 0 || a[j+1] < 0 )
			{
				if(a[j+1] < 0 && a[j] > 0) // 뒤에 수가 음수일 떄만 
				{
					temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
				}
			}
		}
	}
	
	for(int i=0; i<n; i++)
	{
		cout << a[i] <<" ";
	}
	
	return 0;
}
