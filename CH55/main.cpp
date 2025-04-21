#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(int argc, char** argv)
{
	int n;
	cin >> n;
	
	int curr = 1;
	
	stack<int> st;
	vector<char> ch;
	
	for(int i=1; i<=n; i++)
	{
		int tmp;
		cin >> tmp;
		
		st.push(tmp);
		ch.push_back('P');
		
		while(1)
		{
			if(st.empty()) break;
			
			if(st.top() == curr)
			{
				st.pop();
				ch.push_back('O');
				curr++;
			}
			else
			{
				break;
			}
		}
		
	}
	if(!st.empty())
	{
		cout << "impossible";
	}
	else
	{
		for(char c : ch )
		{
			cout << c;
		}
	}
		
	return 0;
}
