#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int ch[21];
vector<pair<int, int>> vNode[21];

int nMinVel = INT_MAX; 
int n,m; 

void Move(int L, int sum)
{
	if(L == n)
	{
		if(sum < nMinVel)
		{
			nMinVel = sum;
		}
	}	
	else
	{
		for(int i=0; i<vNode[L].size(); i++)
		{
			int NextNode = vNode[L][i].first;
			int NextNodeVel = vNode[L][i].second;
			if(ch[NextNode] == 0)
			{
				ch[NextNode] = 1;
				Move(NextNode, sum+NextNodeVel);
				ch[NextNode] = 0;
			}
		}
	}
}

int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int i=0; i<m; i++)
	{
		int a, b, c;
		
		cin >> a >> b >> c;
		
		vNode[a].push_back({b,c});
	}
	ch[1] = 1;
	
	Move(1,0);
	
	cout << nMinVel;
	return 0;
}

