#include <iostream>
#include <vector>
#include <queue>
using namespace std;



int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	priority_queue<int> MaxQue;
	
	int n;
	
	while(1)
	{
		cin >> n;

		if(n == 0)
		{
			int nNode;
			nNode = MaxQue.top();
			MaxQue.pop();
			cout << nNode << endl;
		}
		else if(n == -1)
		{
			return 0;
		}
		else
		{
			MaxQue.push(n);
		}
	}
	
	/* �ּ� ���� ��� Push�� ��� -�� ���� ť�� push �� PoP�� �� �ٽ� -�� �ٿ� POP�Ѵ�. */
	
	return 0;
}
