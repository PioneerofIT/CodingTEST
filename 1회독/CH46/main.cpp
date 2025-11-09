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
	int pos=0, cnt=0, total=0;
	
	// pos : 카운트가 감소함에따라 증가하는 index Pos 변수
	// cnt : 타임 카운트 체크
	// total : 총 작업시간 
	
	vector<int> a(n+1);
	
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
		total += a[i];
	}
	
	int k;
	cin >> k;
	
	if(k >= total) // K 가 크면 이미 모든 작업이 끝난 후 정전 
	{
		cout << "-1" << endl;
		return 0;
	}
	
	
	// 작업 하나 당 1의 카운트가 증가한다. 
	while(1)
	{
		pos++;
		if(pos > n) pos = 1;
		if(a[pos] == 0) continue; // 작업량이 남아 있지 않으면 그냥 건너뛴다.
		
		// 작업량이 있는 로직
		a[pos] --;
		cnt ++;
		if(cnt == k) break; 
		 
	}
	
	// 정전이 끝난 후 다음 작업을 알아내는 과정
	// 주의 사항 : 다음 작업이 a[pos] == 0  이면 출력하면 안됌 
	while(1)
	{
		pos ++;
		if(pos > n) pos = 1; // 항상 인덱스가 마지막인지 체크. 
		if(a[pos] != 0)
			break;
	}
	cout << pos;


	 
	return 0;
}
