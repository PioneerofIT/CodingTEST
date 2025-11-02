#include <iostream>
#include <vector>

using namespace std;

int n,r;
int dy[21][21];

int DFS(int n, int r)
{
	if(dy[n][r] > 0) return dy[n][r];
	
	if(n == r || r == 0)
	{
		return 1;
	}
	else
	{
		return dy[n][r] = DFS(n-1, r-1) + DFS(n-1, r);// 자기자신이 포함된 경우 + 자기자신이 포함되지 않은 경우 
	}
}

int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	
	cin >> n >> r;
	
	cout << DFS(n, r);
	
	return 0;
}
