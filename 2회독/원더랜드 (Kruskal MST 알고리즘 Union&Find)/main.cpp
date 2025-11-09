#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;
int unf[101];

struct Node
{
	int a;
	int b;
	int value;
	
	Node(int x, int y, int z)
	{
		this->a = x;
		this->b = y;
		this->value = z;
	}
	
	bool operator< (const Node &arg) const
	{
		return this->value < arg.value;
	}
};


int Find(int v)
{
	if(v == unf[v]) return v;
	else return unf[v] = Find(unf[v]); 	
}
void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	
	if( a!= b) unf[a] = b;
}

int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	vector<Node> vNode;
	int sum = 0;
	
	int v,e; // µµ½Ã °¹¼ö, µµ·Î °¹¼ö
	cin >> v >> e;
	for(int i=1; i<=v; i++)
	{
		unf[i] = i;
	}
	
	for(int i=1; i<=e; i++)
	{
		int x,y,z;
		cin >> x >> y >> z;
		
		vNode.push_back(Node(x, y, z));
		
	}
		
	sort(vNode.begin(), vNode.end());
	
	
	for(int i=0; i<vNode.size(); i++)
	{
		int a, b;
		a = Find(vNode[i].a);
		b = Find(vNode[i].b);
		if ( a!=b ) 
		{
			Union(a, b);
			sum += vNode[i].value;
		}
			
	}
	
	
	cout << sum;
	 
	return 0;
}
