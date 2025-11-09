#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct Node
{
	int a; //도착 노드 
	int value;
		
	Node(int a, int v)
	{
		this->a = a;
		this->value = v;
	}
	bool operator< (const Node &arg ) const
	{
		return this->value > arg.value; // 최소힙 
	}
};

int main(int argc, char** argv) 
{
	
	int v, e;
	vector<pair<int, int>> vNode[101];
	priority_queue<Node> pQ;
	int visited[101] = {0};
	int res = 0;
	
	cin >> v >> e;
	
	for(int i=0; i<e; i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		
		vNode[a].push_back(make_pair(b, c));
		vNode[b].push_back(make_pair(a, c));
	}
	
	pQ.push(Node(1,0)); //
	
	while(!pQ.empty())
	{
		Node n = pQ.top();
		pQ.pop();
		
		
		if(visited[n.a] == 0) 
		{
			res += n.value;
			visited[n.a] = 1;				
			for(int i=0; i<vNode[n.a].size(); i++) // 방문하지 않은 것에 대해서만 큐에 넣어주자! 
			{
				pQ.push(Node(vNode[n.a][i].first, vNode[n.a][i].second));

			}
		}
		
		
	}
	
	cout << res;
	
	return 0;
}
