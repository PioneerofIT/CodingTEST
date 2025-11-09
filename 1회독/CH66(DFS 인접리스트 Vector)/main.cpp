#include <iostream>
#include <vector>

using namespace std;

vector<int> map[30];
int ch[30];
int n;
int count = 0;

void DFS(int v)
{
	if(v == n)
	{
		count ++;
	}
	else
	{
		for(int i=0; i<map[v].size(); i++)
		{
			if(ch[map[v][i]] == 0)
			{
				ch[map[v][i]] = 1;
				DFS(map[v][i]);
				ch[map[v][i]] = 0;	
			}
		}
	}
}
int main(int argc, char** argv) 
{
	
	int m;
	
	cin >> n >> m;
	
	
	for(int i=0; i<m; i++ )
	{
		int a, b;
		cin >> a >> b;
		
		map[a].push_back(b);
	}
	
	ch[1] = 1;
	DFS(1);
	
	cout << count;
	return 0;
}
