#include <iostream>

using namespace std;

void StackFrame(int x)
{
	if( x == 0)
		return;
	else
	{
		StackFrame(x/2);
		cout << (x%2);
		
	}
} 

int main(int argc, char** argv) 
{
	int n;
	cin >> n;
	
	StackFrame(n);
	return 0;
}
