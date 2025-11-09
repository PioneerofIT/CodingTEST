#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std; 

struct Node
{
	int nIncome;
	int nDay;
	
	Node(int income, int day)
	{
		nIncome = income;
		nDay = day;
	}	
	
	bool operator< (const Node &arg) const
	{
		if(nDay != arg.nDay) return nDay > arg.nDay;
		return nIncome > arg.nIncome;
	}
	
};


int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int max = INT_MIN;
	int res = 0;
	int n;
	vector<Node> vList;
	priority_queue<int> pQ;
	
	cin >> n;
	
	for(int i=0; i<n; i++)
	{
		int tmpDay, tmpIncome;
		cin >> tmpIncome >> tmpDay;
		
		if(tmpDay > max)
		{
			max = tmpDay;
		}
		vList.push_back(Node(tmpIncome, tmpDay));
	}
	
	sort(vList.begin(), vList.end());
	int j=0;  //이미 이전 날짜에 넣었던 강연도 중복으로 큐에 계속 들어가는 것을 방지 
	for(int i=max; i>=1; i--)
	{
		for( ;j<vList.size(); j++)
		{
			if(vList[j].nDay < i) break;
			
			pQ.push(vList[j].nIncome);
		}
		if(!pQ.empty())
		{
			res += pQ.top();
			pQ.pop();	
		} 	
	}
	
	cout << res;
	
	
	return 0;
}
