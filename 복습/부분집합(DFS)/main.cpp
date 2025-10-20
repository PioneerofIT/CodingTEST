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
		ch[L] = 1; //현재 레벨은 부분집합에 참여한다. 
		DFS(L+1);
		ch[L] = 0; //현재 레벨은 부분집합에 참여하지 않는다.
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
