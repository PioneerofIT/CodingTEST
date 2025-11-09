#include <iostream>
#include <algorithm>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int digit_sum(int x);

int main(int argc, char** argv)
{
	int n;
	cin >> n;
	int nArr[n];
	int nRes[n];
	int max = -10000;
	int idx = 0;
	
	for(int i=0; i<n; i++)
	{
		cin >> nArr[i];
	}
	
	for(int i=0; i<n; i++)
	{
		nRes[i] = digit_sum(nArr[i]);
	}
	
	
	for(int i=0; i<n; i++)
	{
		if(max < nRes[i])
		{
			max = nRes[i];
			idx = i;
		}
		else if(max == nRes[i])
		{
			(nArr[idx] < nArr[i]) ? ( idx = i ) : (idx = idx);
		
		}
	}
	
	cout << nArr[idx];
	
	
	return 0;
}

 int digit_sum(int x)
 {
 	int cnt = 0;
	
	while( x !=0 )
 	{
 		cnt += (x % 10);
		x = x / 10;	
	}
	
	return cnt;
	
 }
