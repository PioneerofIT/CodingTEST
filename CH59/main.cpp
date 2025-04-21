#include <iostream>
#include <vector>
using namespace std;

int ch[11] = {0};
int n;
void D(int L)
{
	if(L == n+1)
	{
		for(int i=1; i<=n; i++)
		{
			if(ch[i] == 1)
			{
				cout << i << " ";
			}
		}
		cout << endl;
		return;
			
	}
	else
	{
		ch[L] = 1; 
		D(L+1);
		ch[L] = 0; 
		D(L+1);	
	}	
}

int main(int argc, char** argv) 
{
	cin >> n;
	D(1);
	
	return 0;
}
