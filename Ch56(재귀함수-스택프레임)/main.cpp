#include <iostream>
#include <stack>
#include <vector> 
using namespace std;


void StackFrame(int x)
{
	if( x == 0)
		return;
	else
	{
		StackFrame(x-1);
		cout << x << " ";
	}	
}

int main(int argc, char** argv) 
{
	
	int n;
	cin >> n;
	
	StackFrame(n);
	
	return 0;
}
