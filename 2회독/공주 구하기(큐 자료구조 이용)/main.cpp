#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,k;

int main(int argc, char** argv) 
{
	
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	
	queue<int> Q;
		
	for(int i=1; i<=n; i++)
	{
		Q.push(i);
	}
	
	int cnt = 0;
	while(1)
	{
		if(Q.size() == 1)  // while (Q.size()>1) --> º¯°æ 
		{
			break;
		}
		
		int v = Q.front();
		Q.pop();
		cnt ++;
		if(cnt == k)
		{
			cnt =0;
		}
		else
		{
			Q.push(v);
		}	
	}
	
	int lastNum = Q.front();
	cout << lastNum;
	
	
	return 0;
}
