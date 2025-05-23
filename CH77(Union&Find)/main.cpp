#include <iostream>
#include<vector>
using namespace std;

int unf[1001];

int Find(int v)
{
	if(v == unf[v])
	{
		return v;
	}
	else
	{
		return unf[v] = Find(unf[v]); // ���� �θ��带 ���� 
	}
}


void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	
	if( a != b)
	{
		unf[a] = b;
	}
}

int main(int argc, char** argv) 
{
	int n,m;
	
	cin >> n >> m;
	
	for(int i=1; i<=n; i++)
	{
		unf[i] = i; // unf[]�� ���� �θ� ��带 ����Ų��. 
	}
	
	for(int i=0; i<m; i++)
	{
		int a, b;
		
		cin >> a >> b;
		Union(a,b);	
	}
	
	int x,y;
	cin >> x >> y;
	
	x = Find(x);
	y = Find(y);
	
	if( x == y)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	
	return 0;
}
