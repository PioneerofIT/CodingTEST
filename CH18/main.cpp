#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
/*int main(int argc, char** argv)
{ 
	int N; //N�� ������ �ǽð� ����ġ
	int M; //�� ������ ��ûġ 
	cin >> N >> M;
	bool continueflag = false;

	vector<int> nSub; // ������
	int Cnt = 0;

	vector<int> Res;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		nSub.push_back(temp);

	}

	for (int i = 0; i < N; i++)
	{
		if (nSub[i] > M)
		{
			if(continueflag)
			{
				Cnt++;
			}
			else
			{
				Res.push_back(Cnt);
				Cnt = 0;
			}
			continueflag = true;
			
		}
		else // ���� ���� ���� �� 
		{
			if(continueflag)
			{
				Res.push_back(Cnt);
				Cnt = 0;
			}
			else
			{
				Cnt = 0;
			}
			continueflag = false;
					
		}
	}

	int max = 0;

	for (int i = 0; i < Res.size(); i++)
	{
		if (Res[i] > max) max = Res[i];
	}

	cout << max;



	return 0;
}*/

int main(int argc, char** argv)
{
	int n, a, val, i, cnt =0, max = -214700000;
	
	scanf("%d %d", &n, &val);
	
	for(i=1; i<=n; i++)
	{
		scanf("%d", &a);
		if(a>val) cnt ++;
		else cnt=0;
		
		if(cnt > max) max = cnt;
		
	}
	
	if(max ==0) printf("-1\n");
	else printf("%d\n", max);
	
	return 0;
}
