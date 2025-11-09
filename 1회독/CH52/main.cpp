#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[1501];
int main(int argc, char** argv)
{
	
	int n;
	int p2=1, p3=1, p5=1;
	int min = 2147000000;
	
	data[1] = 1;
	
	cin >> n;
	
	p2=p3=p5=1;
	
	for(int i=2; i<=n; i++)
	{
		if(a[p2]*2 < a[p3]*3 ) min = a[p2]*2;
		else min = a[p3]*3;
		
		if(a[p5]*5 < min) min = a[p5]*5;
		
		//최소값이 일치하다면 동시에 같은 포인터들 증가 
		if(a[p2] == min) p2 ++;
		if(a[p3] == min) p3 ++;
		if(a[p5] == min) p5 ++;
		a[i] = min; 	
	}
	
	cout << a[n];
	
	
	return 0;
}
