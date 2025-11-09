#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	
	vector<int> arr(n, 0);
	
	int tmp;
	
	for(int i=0; i<n; i++)
	{
		cin >> arr[i];
	}
	
	for(int i=0; i<n-1; i++)
	{
		for(int j=0; j<n-1-i; j++) //이미 뒤쪽 i개는 정렬이 완료되었으므로 n-1-i까지만 비교 i=0 일 때 뒤쪽 정렬 완료 
		{
			if(arr[j] > arr[j+1])
			{
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
	
	for(int i=0; i<n; i++) cout << arr[i] << " ";	
	
	
	return 0;
}
