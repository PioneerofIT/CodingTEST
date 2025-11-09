#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Node
{
	int NowNode;
	int NextNode;
	int Value;
	
	Node(int now, int next, int val)
	{
		
		NowNode = now; 
		NextNode = next;
		Value = val;
	}
};
int main(int argc, char** argv) 
{
	int n, m;
	vector<Node> vNode;
	int dist[201];
	for(int i=0; i<=200; i++) dist[i] = INT_MAX;
	dist[1] = 0;
	
	cin >> n >> m;
	
	for(int i=0; i<m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		
		vNode.push_back(Node(a, b, c));
	}
	
	for(int i=1; i<=n-1; i++) //노드가 n개이면 최대로 갈 수 있는 간선은 n-1개 이기 때문에 
	{
		for(int j=0; j<vNode.size(); j++)
		{
			int now = vNode[j].NowNode;
			int next = vNode[j].NextNode;
			int val = vNode[j].Value;
			
			if(dist[next] >(dist[now]+val) )
			{
				dist[next] = dist[now]+val;
			}
		}
	}
	
	int x, y;
	cin >> x >> y;
	
	for(int i=1; i<=n; i++)
	{
		if(dist[i] == INT_MAX)
		{
			cout << -1;
			return 0;
		}
	}
	
	cout << dist[y];
		
	
	return 0;
}
