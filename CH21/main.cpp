#include <iostream>
#include <string>
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// 조건1. 단, 게임 도중 카드의 순서를 바꿀 수는 없다. 
// 조건2. 총점이 같은 경우 마지막 게임을 이긴 사람이 승리
// 조건3. 모든 라운드를 비겼을 땐 비김
// 승자 3점 패자 승점x 비길 시 각각 1점 

/*A와 B가 늘어놓은 카드의 숫자가 순서대로 주어질 때, 게임의 승자가 A인지 B인지, 또는 비겼
는지 결정하는 프로그램을 작성하시오.*/ 
int main(int argc, char** argv)
{
	int A[10], B[10];
	int resA = 0; // 각각의 점수 
	int resB = 0;
	bool compareflag = true;
	char latestWin;
	
	for(int i=0; i<10; i++)
	{
		cin >> A[i];
	}
	
	for(int i=0; i<10; i++)
	{
		cin >> B[i];
	}
	
	// 비겼을 경우 먼저 예외처리
	for(int i=0; i<10; i++)
	{
		if(A[i] != B[i] ) compareflag = false; 	
	}
	
	if(compareflag)
	{
		cout << 10 <<" " << 10 << endl;
		cout << "D";
		return 0;		
	}
	
	for(int i=0; i<10; i++)
	{
		//case 1. A승리 
		if(A[i] > B[i])
		{
			resA += 3;
			latestWin = 'A';	
		}
		//case 2. B승리 
		else if(A[i] < B[i])
		{
			resB += 3;
			latestWin = 'B';
		}
		else if(A[i] == B[i])
		{
			resA += 1;
			resB += 1;	
		}
		
	}
	
	if(resA > resB)
	{
		cout << resA << " " << resB << endl;
		cout << "A";  
	}
	else if (resA < resB)
	{
		cout << resA << " " << resB << endl;
		cout << "B";  	
	}
	else if (resA == resB)
	{
		cout << resA << " " << resB << endl;
		cout << latestWin; 	
	}
	
		
	
	return 0;
}
