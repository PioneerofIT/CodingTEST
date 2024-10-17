#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main(int argc, char** argv)
{
	int n; //곡의 갯수
	int m; // DVD 숫자
	
	cin >> n >> m;
	vector<int> t(n); //곡의 시간
	
	int mid, lt, rt=0;
	vector<int> mintime;
	
	lt = t[1];
	
	for(int i=0; i<n; i++)
	{
		cin >> t[i];
		rt += t[i];	
	}
	
	
	
	while(lt != rt)
	{
		mid = (lt + rt) / 2;
		int temp = 0;
		int cnt = 0;
		
		for(int i=0; i<n; i++)
		{
			temp += t[i];
			
			if(temp > mid )
			{
				temp = t[i];
				cnt ++;
			}
		}
		
		if( cnt > m) //용량이 작다는 것 
		{		
			lt = mid + 1;
		}
		else if (cnt < m)
		{
			rt = mid - 1;
		}
		else
		{
			mintime.push_back(mid);
		}
	}
	sort(mintime.begin(), mintime.end());
	
	cout << mintime[0];
	 
		 
	return 0;
}
