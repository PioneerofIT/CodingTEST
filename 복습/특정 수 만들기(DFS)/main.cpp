#include <iostream>

using namespace std;
int n, m;
int arrNum[11];

int Cnt;

void DFS(int L, int sum)
{
	if(L > n)
	{
		if(sum == m)
		{
			Cnt ++;
		}
		
	}
	else
	{
		DFS(L+1, sum + arrNum[L]); // + �����ڷ� �����ϴ� ���
		DFS(L+1, sum); // �ش� ���Ұ� �������� �ʴ°��
		DFS(L+1, sum- arrNum[L]); // - �����ڷ� �����ϴ� ��� 
		
	}
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	
	cin >> n >> m;
	
	for(int i=1; i<=n; i++)
	{
		cin >> arrNum[i];
	}
	
	DFS(1, 0);
	
	cout << Cnt;
	return 0;
}
