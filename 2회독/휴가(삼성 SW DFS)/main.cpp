#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Node
{
	int T;
	int V;
	
	Node(int t, int v)
	{
		T= t;
		V= v;	
	}	
};


bool visited[16];
vector<Node> vNode;
int n;
int maxSum = INT_MIN;

void DFS(int L, int sum)
{
	if(L == n+1)
	{
		if(maxSum < sum)
		{
			maxSum = sum;
			return;
		}
	}
	else
	{
		int t = vNode[L].T;
		int v = vNode[L].V;
		
		if(L+t <= n+1)
		{
			DFS(L+t, sum+v);
		}
				
		DFS(L+1, sum);
	}
}

int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	vNode.push_back(Node(0, 0));
	for(int i=0; i<n; i++)
	{
		int a, b;
		cin >> a >> b;
		
		vNode.push_back(Node(a, b));
	}
	
	DFS(1,0);
	
	cout << maxSum;
	
	return 0;
}
