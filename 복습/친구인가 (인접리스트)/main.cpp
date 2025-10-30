#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> vList[1001];
int ch[1001];
int n,m;
int p1,p2;

int main(int argc, char** argv) 
{
	queue<int> Q;
	
	cin >> n >> m;
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		
		vList[a].push_back(b);
		vList[b].push_back(a);
		
	}
	
	
	cin >> p1 >> p2;
	ch[p1] = 1;
	
	Q.push(p1);
	while(!Q.empty())
	{
		int v = Q.front();
		Q.pop();
		
		if(vList[v][0] == p2)
		{
			cout << "YES";
			return 0;
		}
			
		for(int i=0; i<vList[v].size(); i++)
		{
			if( vList[v][i] == p2 )
			{
				cout << "YES";
			}
			
			if(ch[vList[v][i] ] == 0)
			{
				ch[vList[v][i]] = 1;
				Q.push(vList[v][i]);
 			}  
		}
	}
	
	cout << "NO";
	
	
	return 0;
}
