#include <iostream>

using namespace std;

int dy[46];
int n;

//�޸����̼� 
int DFS(int L) 
{	
	if(dy[L] > 0 ) return dy[L];
	
	if(L == 1 || L == 2) // ���� ����	 
	{
		return L;	
	}
	else 
	{
		return dy[L] = DFS(L-2) + DFS(L-1);
	}
}

int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	
	cout << DFS(n);

	
	return 0;
}

/*void DFS(int L) 
{
	if(L == 0)
	{
		cnt ++;	
	}
	else
	{
		if(L-2 >= 0)
		{
			DFS(L-2); // 2m�ڸ���� 
		}
		DFS(L-1); // 1m�ڸ� ���	
				
					
	}	
}

int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	DFS(n);
	
	cout << cnt; 
	
	return 0;
}*/
