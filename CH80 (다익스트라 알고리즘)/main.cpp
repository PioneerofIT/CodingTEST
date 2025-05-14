#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int distance[21] = {21470000}; 
int ch[21];

struct Edge
{
	int node;
	int price;
	
	Edge(int a, int b)
	{
		node = a;
		price = b;	
	}
	
	bool operator< (const Edge &arg) const
	{
		return price > arg.price;
	}
};

int main(int argc, char** argv) 
{
	int n,m;
	vector< pair<int,int>> Node[21];
	priority_queue<Edge> pQ;
	
	cin >> n >> m;
	for(int i=0; i<m; i++)
	{
		int x, y, z;
		
		cin >> x >> y >> z;
		
		Node[x].push_back(make_pair(y,z));
	}
	
	pQ.push(Edge(1,0));
	distance[1] = 0;
	ch[1]=1;	
	while(!pQ.empty())
	{
		
		for(int i=1; i<=n; i++ )
		{
			if(min < distance[i])
			{
				min = i;
			}
		}
		
		if(ch[min] == 0)
		{
			for(int i=0; i<Node[min].size(); i++)
			{
				
				if( res < distance[node]+distance[Node[min].frist] ) //현재 자신의 노드와 도착노드의 비용을 더해야함. 
				{
					if(ch[min] == 0)
					{
						distance[Node[node].frist] 	= res;
						ch[min] = 1;
					}
					
				}	
				
				
				pQ.push(Node[min].frist, Node[min].second);
			}			
		}
		
	
					
	}
	
	

	
	return 0;
}
