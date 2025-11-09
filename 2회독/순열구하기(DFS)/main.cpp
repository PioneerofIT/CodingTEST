#include <iostream>
#include <vector>
using namespace std;

int n,r;
int arrNum[16];
int res[16]; 
bool visited[16];
int cnt = 0;

void DFS(int L)
{
	if(L == r)
	{
		cnt++;
		for(int i=0; i<L; i++)
		{
			cout << res[i] << " ";
		}
		cout << endl;
		return;
	}
	else
	{
		for(int i=1; i<=n; i++)
		{
			if(!visited[i])
			{			
				visited[i] = true;
				res[L] = arrNum[i]; // 결과 배열을 따로 둬야 순서가 맞음 !! 
				DFS(L+1);
				visited[i] = false;
			}
		}
	}
}


int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	
	cin >> n >> r;
	
	for(int i=1; i<=n; i++) 
	{
		cin >> arrNum[i];
	}
	
	DFS(0);
	cout << cnt;
	
	return 0;
}
