#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv)
{
	int n, flag;
	int cnt = 0;
	cin >> n;
	for(int i=2; i<=n; i++)
	{
		flag =1;
		for(int j=2; j*j<=i; j++)
		{
			if(i%j == 0)
			{
				flag = 0;
				break;
			}
		}
		if(flag == 1) cnt++;
	}
	cout << cnt;
	return 0;
}
