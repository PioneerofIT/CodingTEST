#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int city[101];
struct Obj
{
	int node1;
	int node2;
	int price;
	
	Obj(int x, int y, int p)
	{
		node1 = x;
		node2 = y;
		price = p;	
	}
	
	bool operator< (const Obj &arg) const
	{
		if(price != arg.price ) return price < arg.price;	
	}
	
};

int Find(int v)
{
	if(v == city[v]) return v;
	else
	{
		return city[v] = Find(city[v]);	
	}	
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	
	if(a!=b)
	{
		city[a] = b;		
	}	
}



int main(int argc, char** argv) 
{
	
	int v, e; // v:도시 e:도로 갯수
	vector<Obj> oV;
	
	int totalCost = 0;
	int edgeCount = 0; 
	
	cin >> v >> e;
	
	for(int i=1; i<=v; i++ )
	{
		city[i] = i;
	}
	
	for(int i=0; i<e; i++)
	{
		int a,b,c;
		
		cin >> a >> b >> c;
		
		oV.push_back(Obj(a,b,c));	
	}
	
	sort(oV.begin(), oV.end());
	
	for(int i=0; i<oV.size(); i++)
	{
		if(Find(oV[i].node1) != Find(oV[i].node2)) //서로 부모 노드가 같다면 -> 아직 두 노드가 연ㄱㄹ되어 있지 않음 
		{
			Union(oV[i].node1,oV[i].node2);
			totalCost += oV[i].price;
			edgeCount++;
			
			if(edgeCount == v-1)
			{
				break;
			}
		}
	}
	
	cout << totalCost << endl; 
	
	
//	for(int i=0; i<oV.size(); i++)
//	{
//		cout << oV[i].node1 <<" " << oV[i].node2 << " " << oV[i].price <<endl;
//	}
	
	
	
	return 0;
}
