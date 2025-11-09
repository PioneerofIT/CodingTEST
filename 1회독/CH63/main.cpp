#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int map[20][20]; 

int main(int argc, char** argv) 
{
	
	int NodeCnt, LineCnt;
	cin >> NodeCnt >> LineCnt;
	
	for(int i=0; i<LineCnt; i++)
	{
		int n = 0;
		int m = 0;
		int price = 0;
		
		cin >> n >> m >> price;
		
		map[n][m] = price;
	}
	
	for(int i=1; i<=NodeCnt; i++)
	{
		for(int j=1; j<=NodeCnt; j++ )
		{
			cout << map[i][j] << " "; 
		}
		cout << endl;
	}
	return 0;
}
