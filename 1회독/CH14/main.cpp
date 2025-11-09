#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
bool IsPrime(int x);
int main(int argc, char** argv) 
{
	int n;
	cin >> n;
	int Res = 0;
	
	for(int i=2; i<=n; i++) // i = 2는 1인 경우는 제외  
	{
		if( IsPrime(i) ) Res++;
	}
	
	cout << Res;
	
	return 0;
}

bool IsPrime(int x)
{
	int Cnt = 0;
	
	
	for(int i=1; i<=x; i++)
	{
		
		if(x % i == 0) 
		{
			Cnt ++;
		}
		
		if(Cnt > 2) return false;
	}
	
	return true;
	
	
}
