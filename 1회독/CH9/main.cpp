#include <iostream>
#include <vector>
#include <algorithm>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

/*n이 3만 이상이면 시간 초과....*/
/*
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int nNum;
	int nCnt = 0;
	
	cin >> nNum;
	
	for(int i=1; i<=nNum; i++ )
	{
		for(int j=1; j<=i; j++)
		{
			if(i % j == 0)
			{
				nCnt ++;
				
			}
		}
		
		cout << nCnt << " ";
		nCnt = 0;
	}
	return 0;
}
*/
int Cnt[50001];
int main(int argc, char** argv)
{
	int n;
	
	cin >> n;
	
	for(int i=1; i<=n; i++)
	{
		for(int j=i; j<=n; j=j+i)
		{
			Cnt[j]++;
		}
	}
	for(int i=1; i<=n; i++)
	{
		cout << Cnt[i] << " ";
	}
	return 0;
}

