#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	//�ϴ� n +1 �� ��ŭ ���� �� �� �� ���� �Է� �޴´�..
	//k : ���� Ÿ�̸� -- �� �� �ش� pos ���� �ϳ��� -- ���ش�.
	//k �� �� �����Ǿ� break �Ǿ��� �� ���� �ε��� ���� ����Ѵ� �� ���� ���� for������ vecotr�� ��� 0�̸� -1�� ���
	
	int n;
	cin >> n;
	
	vector<int> a(n+1);
	
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	
	int k;
	cin >> k;
	
	int pos = 1;
	int cnt = 0;
	
	
	// k=5 start
	while(k != 0)
	{
		if(a[pos] != 0)
		{
			a[pos] --;
		}
		else
		{
			cnt ++;
			pos ++;
			a[pos] --;
		}
		if(pos == n)
			pos = 1;
		
		k--;	
	}
	
	if(cnt == n)
	{
		cout << "-1" ;
	}
	for(int i=1; i<=n; i++)
	{
		if(a[i] != 0 )
		{
			cout << a[i];
			return 0;			
		}		
	}

	 
	return 0;
}
