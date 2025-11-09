#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

/* 다익스트라 알고리즘 : 하나의 시작 노드에서 모든 노드로 가는 최단 거리를 구하는 그리디 기반의 그래프 알고리즘*/
struct Node
{
	int node;
	int value;
	
	Node(int n, int v)
	{
		this->node = n;
		this->value = v;
	}
	
	bool operator< (const Node &arg) const
	{
		return this->value > arg.value;
	}
};

int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	
	int n,m;
	vector<Node> vNode[21];
	priority_queue<Node> pQ;
	int visited[21] = {0};
	int dist[21];
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) dist[i] = INT_MAX; // 매우 큰 값
	dist[1] = 0; // 시작 노드는 거리 0
		
	
	
	for(int i=0; i<m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		
		vNode[a].push_back(Node(b, c));
	}
	
	pQ.push(Node(1, 0));
	
	while(!pQ.empty())
	{
		Node now = pQ.top();
		pQ.pop();
		
		if(visited[now.node] == 1) continue;
		
		visited[now.node] = 1;	
	
		for(int i=0; i<vNode[now.node].size(); i++)
		{
			int nextNode = vNode[now.node][i].node;
			int newDist = dist[now.node]  + vNode[now.node][i].value;
			/*노드1(최소거리) + 노드2(최소거리) = 최소거리 , 최소 누적*/ 
			if(newDist < dist[nextNode])
			{
				dist[nextNode] = newDist;
				pQ.push(Node(nextNode,newDist ));
			} 
			
			
		}
		
	}
	for (int i = 2; i <= n; i++) 
	{
	    if (dist[i] == 2147000000) cout << i << " : impossible\n";
	    else cout << i << " : " << dist[i] << "\n";
	}
	
	return 0;
}
