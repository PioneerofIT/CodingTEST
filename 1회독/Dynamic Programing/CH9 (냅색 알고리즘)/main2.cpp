#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	
	int v, w; // 보석의 종류, 무게 한계
	cin >> v >> w;
	
	vector<int> dy(w+1, 0);
	
	for(int i=0; i<v; i++)
	{
		int m, p;
		
		cin >> m >> p;
		
		for(int j=m; j<=w; j++ )
		{
			dy[j] = max(dy[j], dy[j-m]+p);
		}
	}
	
	cout << dy[w];
	
	return 0;
}
