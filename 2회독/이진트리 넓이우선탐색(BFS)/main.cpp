#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main(int argc, char** argv) 
{
	vector<int> graph [8];
	queue<int> Q;
	int ch[8] ={0};
	
	for(int i=1; i<=6; i++)
	{
		int a,b;
		cin >> a >> b;
		
		graph[a].push_back(b);
		graph[b].push_back(a); // ¾ç¹æÇâ Å½»ö 
	}
	
	Q.push(1);
	ch[1] = 1;
	
	
	while(!Q.empty())
	{
		int nNode = Q.front();
		
		Q.pop();
		
		cout << nNode << " ";
		
		for(int i=0; i<graph[nNode].size(); i++)
		{
			if(ch[graph[nNode][i]] == 0)
			{
				Q.push(graph[nNode][i]);
				ch[graph[nNode][i]] = 1;	
			
			} 	
		}	
	}
	
	return 0;
}
