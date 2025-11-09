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
		DFS(L+1, sum + arrNum[L]); // + 연산자로 참여하는 경우
		DFS(L+1, sum); // 해당 원소가 참여하지 않는경우
		DFS(L+1, sum- arrNum[L]); // - 연산자로 참여하는 경우 
		
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
