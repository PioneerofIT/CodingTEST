#include <iostream>

using namespace std;


int n;
int arrNum[11];
//int ch[11];
//int sum = 0;
int total = 0;
bool IsExistSame = false;

void DFS(int L, int sum )
{
	if(L> n)
	{
		if(total - sum == sum)
		{
			IsExistSame = true;		
		}	
	}
	else
	{

		DFS(L+1, sum + arrNum[L]); //집합에 참여하는 경우
		
		DFS(L+1, sum); //집합에 참여하지 않는 경우
	}
}

int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	
	for(int i=1; i<=n; i++)
	{
		cin >> arrNum[i];
		
		total += arrNum[i];
	}
	
	DFS(1,0);
	
	if(IsExistSame)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	
	return 0;
}
