#include <iostream>
#include <vector>
#include <queue>
using namespace std;


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
	vector<pair<int,int>> Node[21];
	priority_queue<Edge> pQ;
	
	
	cin >> n >> m;
	
	vector<int> distance(n+1, 21700000);
	for(int i=0; i<m; i++)
	{
		int x, y, z;
		
		cin >> x >> y >> z;
		
		Node[x].push_back(make_pair(y,z));
	}
	
	pQ.push(Edge(1,0));
	distance[1] = 0;	
	while(!pQ.empty())
	{
		
		int nowNode = pQ.top().node;
		int nowPrice = pQ.top().price;
		pQ.pop();
		
		if(nowPrice > distance[nowNode] ) continue;
		
		for(int i=0; i<Node[nowNode].size(); i++)
		{
			int nextNode = Node[nowNode][i].first;
			int nextPrice = nowPrice + Node[nowNode][i].second;
			
			if(distance[nextNode] > nextPrice )
			{
				distance[nextNode] = nextPrice;
				pQ.push(Edge(nextNode,nextPrice));
			}
		}
		
	}			
		

	
	return 0;
}
