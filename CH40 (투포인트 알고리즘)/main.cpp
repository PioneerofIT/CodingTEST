#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// �� �ڵ� Time_exceed... 
//int main(int argc, char** argv)
//{
//	int n,m;
//	cin >> n;
//	
//	vector<int> a(n);
//	for(int i=0; i<n; i++)
//	{
//		cin >> a[i];
//	}
//	
//	cin>> m;
//	vector<int> b(m);
//	for(int i=0; i<m; i++)
//	{
//		cin >> b[i];
//	}
//	
//	vector<int> c;
//	
//	for(int i=0; i<n; i++)
//	{
//		for(int j=0; j<m; j++)
//		{
//			if(a[i] == b[j])
//			{
//				c.push_back(a[i]);
//			}
//		}
//	}
//	
//	int i,j;
//	int temp;
//	for(i=1; i<c.size(); i++)
//	{
//		temp = c[i];
//		for(j=i-1; j>=0; j--)
//		{
//			if(c[j] > temp )
//			{
//				c[j+1] = c[j];
//			}
//			else
//				break;	
//		}
//		c[j+1] = temp;	
//	}
//	
//	for(i=0; i<c.size(); i++)
//	{
//		cout << c[i] << " ";
//	}
//	
//	return 0;
//}

int main(int argc, char** argv)
{
	int n,m;
	cin >> n;
	
	vector<int> a(n);
	for(int i=0; i<n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end()); // sort --> �������� ���� (�� ����) 
	
	cin >> m;
	vector<int> b(m);
	for(int i=0; i<m; i++)
	{
		cin >> b[i];
	}
	sort(b.begin(), b.end()); // sort --> �������� ���� (�� ����)
	
	vector<int> c(n+m);
	int p1=0, p2=0, p3=0;
	
	while(p1 < n && p2 < m ) //n�� ũ�� p1�� �ε��� ������ �򰥸��� ����.. �ε��� �����Ͱ� ũ��� ���� ���� �ȵȴ�.
	{
		if(a[p1] == b[p2])
		{
			c[p3++] = a[p1++];
			p2 ++;	
		}
		else if(a[p1] < b[p2]) p1++;
		else p2++;	
	}
	
	for(int i=0; i<p3; i++)
	{
		cout << c[i] << " ";
	}	 
		
	return 0;
}
