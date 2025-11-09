#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char** argv) 
{
	int a;
	priority_queue<int> pQ;
	
	while(1)
	{
		cin >> a;
		
		if( a == -1) return 0;
		else if( a == 0 )
		{
			cout << pQ.top() << endl;
			pQ.pop();
		}
		else
		{
			pQ.push(a);
		}
	}	
	
	return 0;
}
