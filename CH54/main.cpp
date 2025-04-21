#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

/*  	stack.push(val)
		stack.pop(void)
		stack.top() : 가장 위의 자료 참조만
		stack.empty() 		
*/

int main(int argc, char** argv)
{
	stack<char> s;
	
	char a[30];
	
	scanf("%s", &a);
	
	for(int i=0; a[i] != '\0'; i++)
	{
		if( a[i] == '(')
		{
			s.push(a[i]);
		}
		else // pop
		{
			if(s.empty())
			{
				cout << "NO";
				return 0;
			}
			else
			{
				s.pop();
			}
		}
	}
	
	if(s.empty()) cout << "YES";
	else cout <<"NO";
	
	return 0;
}


