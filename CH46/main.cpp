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
	int pos=0, cnt=0, total=0;
	
	// pos : ī��Ʈ�� �����Կ����� �����ϴ� index Pos ����
	// cnt : Ÿ�� ī��Ʈ üũ
	// total : �� �۾��ð� 
	
	vector<int> a(n+1);
	
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
		total += a[i];
	}
	
	int k;
	cin >> k;
	
	if(k >= total) // K �� ũ�� �̹� ��� �۾��� ���� �� ���� 
	{
		cout << "-1" << endl;
		return 0;
	}
	
	
	// �۾� �ϳ� �� 1�� ī��Ʈ�� �����Ѵ�. 
	while(1)
	{
		pos++;
		if(pos > n) pos = 1;
		if(a[pos] == 0) continue; // �۾����� ���� ���� ������ �׳� �ǳʶڴ�.
		
		// �۾����� �ִ� ����
		a[pos] --;
		cnt ++;
		if(cnt == k) break; 
		 
	}
	
	// ������ ���� �� ���� �۾��� �˾Ƴ��� ����
	// ���� ���� : ���� �۾��� a[pos] == 0  �̸� ����ϸ� �ȉ� 
	while(1)
	{
		pos ++;
		if(pos > n) pos = 1; // �׻� �ε����� ���������� üũ. 
		if(a[pos] != 0)
			break;
	}
	cout << pos;


	 
	return 0;
}
