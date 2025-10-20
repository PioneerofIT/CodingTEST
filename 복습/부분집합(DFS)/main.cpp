#include <iostream>

using namespace std;

int n;
int ch[11];

void DFS(int L)
{
	if(L > n)
	{
		for(int i=1; i<=n; i++)
		{
			if(ch[i] == 1)
			{
				cout << i << " ";
			}
		}
		cout << endl;
		
	}
	else
	{
		ch[L] = 1; //���� ������ �κ����տ� �����Ѵ�. 
		DFS(L+1);
		ch[L] = 0; //���� ������ �κ����տ� �������� �ʴ´�.
		DFS(L+1); 
		
	}
}

int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	
	
	cin >> n;
	DFS(1);
	
	return 0;
}
