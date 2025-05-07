#include <iostream>
#include <vector>
using namespace std;

int Q[10];
vector<int> map[10];
int ch[10];

int main(int argc, char** argv) 
{
	
	for(int i=1; i<=6; i++)
	{
		int a,b;
		cin >> a >> b;
		
		map[a].push_back(b);
		map[b].push_back(a);
		
	}
	
	int back = -1;
	int front = -1;
	
	ch[1] = 1;
	Q[++back] = 1;
	while(front < back) // 더 이상 꺼낼게 없을 때 까지
	{	
		int x = Q[++front];
		cout << x << " ";
		
		for(int i=0; i<map[x].size(); i++)
		{
			if(ch[map[x][i]] == 0)
			{
				ch[map[x][i]] = 1;
				Q[++back] = map[x][i];
			} 
		}
				
	} 
	return 0;
}
