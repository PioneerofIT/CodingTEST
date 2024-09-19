#include <iostream>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) 
{
	int N;
	cin >> N;
	int Data[N];
	
	bool IsJumper[N]; // 1~N-1
	
	for(int i=0; i<N; i++)
	{
		cin >> Data[i];
	}
	
	for(int i=0; i<N; i++)
	{
		int tmp = abs( Data[i] - Data[i+1]); //알아두기 abs->절댓값 함수 헤더는 <stdlib.h> 
		
		if(tmp >=1 && tmp <= N-1)
		{
			IsJumper[tmp] = true;
		}
	
	}
	
	for(int i=1; i<N; i++)
	{
		if(!IsJumper[i] )
		{
			cout <<"NO";
			return 0;
		}
	}
	
	cout << "YES";	
	
	
	return 0;
}
