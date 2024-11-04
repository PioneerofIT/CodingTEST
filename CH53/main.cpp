#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int top = -1;
int k;
int data[1000];
void push(int val);
int pop();

int main(int argc, char** argv) 
{
	int n;
	
	
	cin >> n >> k;
	
	while(n != 0)
	{
		push( n % k );
		n = n/k;
		
	}
	
	while(top != -1)
	{
	
		int tmp = pop();
		if(k == 16)
		{
			switch (tmp)
			{
				case 10:
					cout << 'A';
					break;	
				case 11:
					cout << 'B';
					break;
				case 12:
					cout << 'C';
					break;
				case 13:
					cout << 'D';
					break;
				case 14:
					cout << 'E';
					break;
				case 15:
					cout << 'F';
					break;
				default:
					cout << tmp;
					break;					
				
			}
		}
		else
		{
			cout << tmp;
		}
	}
	 	
	return 0;
}

void push(int val)
{
	data[++top] = val;
}

int pop()
{
	return data[top--];	
}
