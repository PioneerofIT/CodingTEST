#include <iostream>

using namespace std;

int n, r;
int mol=1;
int deno=1;
void DFS(int n, int r)
{
	if(r==0)
	{
		return;	
	}
	else
	{
		mol *= n;
		deno*= r; 
		DFS(n-1,r-1);		
	}
	
	
		
}

int main(int argc, char** argv) 
{

	
	cin >> n >> r;
	
	DFS(n,r);
	
	cout << mol/deno;
	return 0;
}
