#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
vector<pair<int,int>> hs;
vector<pair<int,int>> pz;
int map[51][51];
int ch[20];
int minRes = 2147000000;
int sum, dis;

void DFS(int L, int s)
{
	if(L == m)
	{
		sum =0;
		for(int i=0; i<hs.size(); i++)
		{
			int x1 = hs[i].first;
			int y1 = hs[i].second;
			dis = 2147000000;
			
			for(int j=0; j<m; j++)
			{
				int x2 = pz[ch[j]].first;
				int y2 = pz[ch[j]].second;
				
				dis = min(dis, abs(x1-x2)+abs(y1-y2));	
			}
			sum += dis;		
		}
		if(minRes > sum) minRes = sum;			
	}
	else
	{
		for(int i=s; i<pz.size(); i++)
		{
			ch[L] = i;
			DFS(L+1, i+1);	
		}	
	}
	
}
int main(int argc, char** argv) 
{
	
	cin >> n >> m;
	
	for(int i=1; i<=n; i++) //row
	{
		for(int j=1; j<=n; j++) // col
		{
			cin >> map[i][j];
			
			if(map[i][j] == 1) 
			{
				hs.push_back(make_pair(i,j));		
			}
			else if(map[i][j] == 2)
			{
				pz.push_back(make_pair(i,j));			
			}
		}
	}
	
	DFS(0,0);
	cout << minRes;
	
	return 0;
}
