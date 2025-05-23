#include <iostream>
#include <vector> 
#include <queue>
using namespace std;
int ch[31];

struct PoQ
{
	int des;
	int price;
	PoQ(int d, int p)
	{
		des = d;
		price = p;
	}

	bool operator< (const PoQ &arg) const
	{
		return price >arg.price; // 오름차순  	
	} 	
};	
int main(int argc, char** argv) 
{
	int v,e;
	vector< pair<int,int>> map[30];
	priority_queue<PoQ> pQ;
	int totalprice = 0;
	
	cin >> v >> e;
	

	
	for(int i=1; i<=e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		
		map[a].push_back(make_pair(b,c));
		map[b].push_back(make_pair(a,c));
	}
	
	pQ.push(PoQ(1,0));
	
	while(!pQ.empty())
	{
		PoQ tmp = pQ.top();
		pQ.pop();
		
		int val = tmp.des;
		int price = tmp.price;
		
		if(ch[val] == 0)
		{
			totalprice += price;
			ch[val] = 1;
			for(int i=0; i<map[val].size(); i++)
			{
				if(ch[map[val][i].first] == 0)
					pQ.push(PoQ(map[val][i].first, map[val][i].second));
					
			}		
		}
			
	}
	cout << totalprice; 
	
	
	return 0;
}
