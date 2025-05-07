#include <iostream>
#include <queue>

using namespace std;
int ch[1001];
queue<int> Q;
int main(int argc, char** argv) 
{
	int N, K;
	cin >> N >> K;
	
	for(int i=1; i<=N; i++)
	{
		Q.push(i);
	}
	int count = K;
	int x;
	while(1)
	{
	
		x = Q.front();
		Q.pop();
		if(Q.empty())
		{
			cout << x;
			break;
		}
		
		count --;
		if(count == 0 && ch[x] == 0)
		{
			ch[x] = 1;
			count = K;
		}
		else
		{
			if(ch[x] == 0 )
			{
				Q.push(x);
			}
		}
		

		
	}
	return 0;
}
