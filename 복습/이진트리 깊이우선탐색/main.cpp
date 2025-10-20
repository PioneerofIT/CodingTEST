#include <iostream>

using namespace std;

void DFS(int L)
{
	if(L > 7)
	{
		return;
	}
	else
	{
//		DFS(L+1); // 전위순회 출력
		
		DFS(L*2);
		
		DFS(L*2+ 1); 
		
		cout << L << " ";
		 
	}
}

int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false); 
	
	DFS(1);
	return 0;
}
