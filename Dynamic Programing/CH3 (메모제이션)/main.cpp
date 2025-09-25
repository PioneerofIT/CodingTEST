#include <iostream>
using namespace std; 
int n;
int dy[26] = {0};

int DFS(int n)
{
	if(dy[n] > 0) return dy[n];
	if( n == 1 || n == 2)
	{
		return n;
	}
	else
	{
		return dy[n] = DFS(n-1) + DFS(n-2)  ;
	}
}

int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	
	cout << DFS(n);
	return 0;
}
