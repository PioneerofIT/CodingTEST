#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	int n; //동전의 종류 수
	int w; // 최대 금액 
	cin >> n;
	vector<int> coin(n);
	
	for(int i=0; i<n; i++)
	{
		int a;
		cin >> a;
		
		coin.push_back(a);
	}
	cin >> w;
	
	vector<int> dy(w+1, 1000);
	dy[0] = 0;
	for(int i=0; i<coin.size(); i++)
	{
		for(int j=coin[i]; j<=w; j++ )
		{
			dy[j] = min(dy[j], dy[j-coin[i]]+1);
		}
		
	}
	
	cout << dy[w];
	
	 
	return 0;
}
