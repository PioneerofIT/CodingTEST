#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*������ �ٽ� ����Ʈ*/
// 1. ��� ���� ��ȣ '('�� �ݵ�� ���� ��ȣ ')'�� ������ �Ѵ�.
// 2. ��� ���������� ���� ��ȣ ')'�� ���� ���� ��ȣ '('�� ���� �ʰ��ؼ��� �ȵȴ�. ��, ������ ��ȣ�� �������� �ݵ�� �� ������ ������ ��ȣ�� �־�� �Ѵ�. 
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
