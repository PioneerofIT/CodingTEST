#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) 
{
	
	int Cnt[9] = {0};
	int sum = 0;
	
	int N;
	cin >> N;
	
	//ex i = 11
	for(int i=i; i<=N; i++)
	{
		int tmp = i;
		
		while( tmp != 0)
		{
			Cnt[tmp%10] ++;
			tmp = tmp /10;
		}
	
	}
	
	for(int i=0; i<=9; i++ )
	{
		sum += Cnt[i];	
	} 	
	
	cout << sum;
	return 0;
}

