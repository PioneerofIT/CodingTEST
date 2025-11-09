#include <iostream>
#include <vector>
using namespace std;
int dist[101]; 

struct Edge
{
	int StartNode;
	int NextNode;
	int Price;
	
	Edge (int a, int b, int c)
	{
		StartNode = a;
		NextNode = b;
		Price = c;	
	}
};

int main(int argc, char** argv) 
{
	
	int n, m;
	cin >> n >> m;
	
	vector<Edge> vQ;
	
	for(int i=0; i<m; i++)
	{
		int a, b, c;
		
		cin >> a >> b >> c;
		
		vQ.push_back(Edge(a,b,c));
	}
	for(int i=1; i<=n; i++)
	{
		dist[i] = 2147000000;
	}
	
	int e,q;
	cin >> e >> q;
	
	dist[e] = 0;
	
	for(int i=1; i<n; i++) // n-1 간선 
	{
		for(int j=0; j<vQ.size(); j++)
		{
			int s = vQ[j].StartNode;
			int n = vQ[j].NextNode;
			int w = vQ[j].Price;
			
			if(dist[s] != 2147000000 && dist[s]+w < dist[n])
			{
				dist[n] = dist[s]+w; 	
			}
		}
		
	}
	
	for(int i=0; i<vQ.size(); i++) //음의 사이클 판별 
	{
		int s = vQ[i].StartNode;
		int n = vQ[i].NextNode;
		int w = vQ[i].Price;
		
		if(dist[s] != 2147000000 && dist[s]+w < dist[n])
		{
			cout << -1;
			exit(0);		
		}	
	}
	
	cout << dist[q];
	
	
	
	return 0;
}
