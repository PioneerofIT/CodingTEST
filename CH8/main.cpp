#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*문제의 핵심 포인트*/
// 1. 모든 열린 괄호 '('는 반드시 닫힌 괄호 ')'로 닫혀야 한다.
// 2. 어떠한 시점에서도 닫힌 괄호 ')'의 수가 열린 괄호 '('의 수를 초과해서는 안된다. 즉, 닫히는 괄호가 나오려면 반드시 그 이전에 열리는 괄호가 있어야 한다. 
using namespace std;
int main(int argc, char** argv)
{
	int LeftCnt=0;
	
	string sTmp;
	cin >> sTmp;
	
	for(int i=0; i<sTmp.size(); i++)
	{
		if(sTmp[i] == '(') LeftCnt++;
		else if(sTmp[i] == ')') LeftCnt --; 
		
		if (LeftCnt < 0)
		{
          cout << "NO";
          return 0;
        } 	
	}
	
	if(LeftCnt == 0) cout <<"YES";

	return 0;
}
