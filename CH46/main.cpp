#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	//일단 n +1 값 만큼 벡터 선 언 후 값을 입력 받는다..
	//k : 정전 타이머 -- 일 때 해당 pos 값을 하나씩 -- 해준다.
	//k 가 다 소진되어 break 되었을 때 다음 인덱스 값을 출력한다 그 전에 만약 for문으로 vecotr이 모두 0이면 -1을 출력
	
	int n;
	cin >> n;
	
	vector<int> a(n+1);
	
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	
	int k;
	cin >> k;
	
	int pos = 1;
	int cnt = 0;
	
	
	// k=5 start
	while(k != 0)
	{
		if(a[pos] != 0)
		{
			a[pos] --;
		}
		else
		{
			cnt ++;
			pos ++;
			a[pos] --;
		}
		if(pos == n)
			pos = 1;
		
		k--;	
	}
	
	if(cnt == n)
	{
		cout << "-1" ;
	}
	for(int i=1; i<=n; i++)
	{
		if(a[i] != 0 )
		{
			cout << a[i];
			return 0;			
		}		
	}

	 
	return 0;
}
