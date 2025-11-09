#include <iostream>
#include <queue>

using namespace std;
int ch[1001];
queue<int> Q;
int main(int argc, char** argv) 
{
	int n, k;
	
	cin >> n >> k;
	
	for(jnt i=1; i<=k; i++)
	{
		Q.push(i);
	}
	
	while(!Q.empty())
	{
		for(int i=1; i<k; i++) // 2 번 째 까지만 pop 
		{
			Q.push(Q.front());
			Q.pop();
			
		}
		Q.pop(); // 마지막 3 번 째에서 pop하고 size 체크 
		if(Q.size() == 1)
		{
			cout << Q.front();
			Q.pop();		
		} 
	}
	return 0;
}
