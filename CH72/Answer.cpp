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
		for(int i=1; i<k; i++) // 2 �� ° ������ pop 
		{
			Q.push(Q.front());
			Q.pop();
			
		}
		Q.pop(); // ������ 3 �� °���� pop�ϰ� size üũ 
		if(Q.size() == 1)
		{
			cout << Q.front();
			Q.pop();		
		} 
	}
	return 0;
}
