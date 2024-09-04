#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv)
{

	int nCnt[10] = { 0 };
	string strNum;
	int maxidx = -1;
	int maxCnt = -1;

	cin >> strNum;

	for (int i = 0; i<strNum.size(); i++)
	{
		int tmp = (strNum[i] - '0');
		nCnt[tmp]++;
	}

	for (int i = 1; i < 10; i++)
	{
		if (maxCnt < nCnt[i])
		{
			maxidx = i;
			maxCnt = nCnt[i];
		}
		else if (nCnt[i] == maxCnt)
		{
			(maxidx > i) ? maxidx = maxidx : maxidx = i;
		}
	}

	cout << maxidx;



	return 0;
}
