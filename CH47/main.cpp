#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* ��Ű���� */

/*�����ڸ��� �����ϹǷ� Col�� Row�� ó���� ���� ���ԵǸ� �ȵȴ�. */
// �ڽ��� �����¿� ���ں��� ū ���ڴ� ���츮 ����
int main(int argc, char** argv)
{
	int n;
	cin >> n;
	
	int a[52][52] = {0};
	int col, row;
	int cnt = 0; // ���츮 ����  
	
	for(col = 1; col <=n; col ++)
	{
		for(row = 1; row<=n; row++)
		{
			cin >>a[col][row];  
		}
	}
	
	// col-major �� ���� �� ���� �ݴ�� ����� ������ 
	for(col = 1; col <=n; col ++)
	{
		for(row = 1; row<=n; row++)
		{
			if(a[col-1][row] < a[col][row] && a[col][row-1] < a[col][row] && a[col+1][row] < a[col][row] && a[col][row+1] < a[col][row]   )
			{
				cnt ++;
			}
		}
	}
	
	cout << cnt ;
	
	
	 
//	for(row = 1; row <=n; row ++)
//	{
//		for(col = 1; col<=n; col++)
//		{
//			cout << " " << a[col][row];  
//		}
//		cout << endl;
//	} 
//	 
	 
	 
	return 0;
}
