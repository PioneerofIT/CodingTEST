#include <iostream>
#include <queue> 
#include <vector>
using namespace std;

int dy[3] = {1,-1,5};
int ch[10001];

int main(int argc, char** argv) 
{
	int start, end, pos;//현재포지션
	cin >> start >> end;
 	
 	queue<int> Q;
	ch[start] = 1;
	Q.push(start);
 	
 	int x;
 	while(!Q.empty())
 	{
 		x= Q.front();
		Q.pop();
		
		for(int i=0; i<3; i++)
		{
			pos = x+dy[i];
			if(pos<=0 || pos>10000) continue;
			if(pos == end)
			{
				cout << ch[x];
				exit(0); 		
			}
			if(ch[pos] == 0)
			{
				ch[pos] = ch[x] + 1;
				Q.push(pos);	
			}	
		}	
	}
 	
	
 	
	return 0;
}
