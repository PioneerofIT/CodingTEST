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
		for(int j=0; j<n-1-i; j++) //�̹� ���� i���� ������ �Ϸ�Ǿ����Ƿ� n-1-i������ �� i=0 �� �� ���� ���� �Ϸ� 
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
