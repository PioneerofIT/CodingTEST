#include <iostream>
#include <vector>

using namespace std;

int ch[21];
vector<int> vNode[21];

int cnt=0;
int n,m; 

void Move(int L)
{
	if(L == n)
	{
		cnt++;	
	}	
	else
	{
		for(int i=0; i<vNode[L].size(); i++)
		{
			if(ch[vNode[L][i]] == 0 )
			{
				ch[vNode[L][i]] = 1;
				Move(vNode[L][i]);
				ch[vNode[L][i]] = 0;	
			
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
		int a, b;
		
		cin >> a >> b;
		
		vNode[a].push_back(b);
	}
	ch[1] = 1;
	
	Move(1);
	
	cout << cnt;
	return 0;
}
