#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 아키텍쳐 */

/*가장자리를 제외하므로 Col과 Row이 처음과 끝이 포함되면 안된다. */
// 자신의 상하좌우 숫자보다 큰 숫자는 봉우리 지역
int main(int argc, char** argv)
{
	int n;
	cin >> n;
	
	int a[52][52] = {0};
	int col, row;
	int cnt = 0; // 봉우리 갯수  
	
	for(col = 1; col <=n; col ++)
	{
		for(row = 1; row<=n; row++)
		{
			cin >>a[col][row];  
		}
	}
	
	// col-major 열 먼저 행 나중 반대는 행먼저 열나중 
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
