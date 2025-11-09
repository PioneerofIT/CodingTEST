#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
 
int n,m;

vector<pair<int, int>> vPizza;
vector<pair<int, int>> vHome;
int comb[12];

int minDist = INT_MAX;
void DFS(int L, int s)
{
	if(L == m)
	{
		int res = 0;
		for(int i=0; i<vHome.size(); i++)
		{
			int xx1 = vHome[i].first;
			int yy1 = vHome[i].second;
			int dist = INT_MAX;
			
			for(int j=0; j<m; j++)
			{
				int idx = comb[j];
				int xx2 = vPizza[idx].first;
				int yy2 = vPizza[idx].second;
				
				int d = abs(xx1 - xx2) + abs(yy1 - yy2);
				dist = min(dist,d); // 각 집에대한 피자최소배달거리 
			}
			res += dist;
			
		}
		minDist = min(res, minDist);
		
	}
	else
	{
		for(int i=s; i<vPizza.size(); i++)
		{
			comb[L] = i;
			DFS(L+1, i+1);
		}
	}
}


int main(int argc, char** argv) 
{
	cin >> n >> m;
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			int x;
			cin >> x;
			if(x == 1) vHome.push_back(make_pair(i,j));
			else if(x == 2) vPizza.push_back(make_pair(i,j));
				
		}
	}
	DFS(0,0);
	
	cout << minDist;
	
	
	return 0;
}
