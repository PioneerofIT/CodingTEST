#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 
using namespace std;



struct PoC
{
	int time;
	int income;
	
	PoC(int x, int y)
	{
		income = x;
		time = y;
	}
	
	bool operator< (const PoC &o ) const
	{
		if(time != o.time) return time > o.time;
		if(income != o.income) return income > o.income;
	}
};

int main(int argc, char** argv) 
{
	
	priority_queue<int> pQ;
	vector<PoC> Object;
	int N;
	int total;
	int max = -2170000;
	
	cin>> N;
	
	for(int i=0; i<N; i++)
	{
		int a,b;
		cin >> a >> b;
		Object.push_back(PoC(a,b));
		
		if(max < b) max = b;	
	}
	sort(Object.begin(), Object.end());
	
	int j=0;
	for(int i=max; i>=1; i--)
	{
		for( ; j<N; j++)
		{
			if(Object[j].time < i) break;
			pQ.push(Object[j].income);
			
		}
		if(!pQ.empty())
		{
			total += pQ.top();
			pQ.pop();			
		}

	}
	cout << total;
	
//	for(int i=0; i<N; i++)
//	{
//		cout << Object[i].income <<" "<<Object[i].time << endl;
//	}
	
	return 0;
}
