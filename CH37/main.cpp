#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	
	int s, n;
	cin >> s; // 캐시의 크기
	cin >> n; //작업의 갯수
	
	vector<int> ch(s);
	vector<int> job(n);
	
	int i,j;
	int pos;
	
	
	for(int i=0; i<n; i++)
	{
		cin >> job[i];	
	}
	
	for(i=0; i<job.size(); i++)
	{
		pos = -1;
		for(j=0; j<ch.size(); j++)
		{
			if(job[i] == ch[j])
			{
				pos = j; // Cache Hit 포지션 저장 
			}
				
		}
		
		// 1) Cache Miss : Cache의 없는 작업이 새로 들어오면 모든 작업 밀고 첫번째로	 
		if(pos == -1)
		{
			for(j=(ch.size()-1); j>=1; j-- )
			{
				ch[j] = ch[j-1]; // 한 칸씩 뒤로 밀고 
			}
			ch[0] = job[i]; // 현재 잡을 첫번째 캐시로 
		}
		// 2) Cache Hit : 
		else
		{
			for(j=pos; j>=1; j--)
			{
				ch[j] = ch[j-1];
			}
			ch[0] = job[i];
		}		
	} 
	
	for(i=0; i<ch.size(); i++)
	{
		cout << ch[i] << " ";
	}
	
	
	return 0;
}
