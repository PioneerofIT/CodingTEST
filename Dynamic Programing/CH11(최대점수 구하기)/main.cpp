#include <iostream>
#include <vector>
using namespace std; 

int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	
	int n,lt;
	cin >> n >> lt;
	
	vector<int> dy(lt+1, 0);
	
	for(int i=0; i<n; i++)
	{
		int v, t;
		cin >> v >> t;
		
		for(int j=lt; j>=t; j--)
		{
			dy[j] = max(dy[j], dy[j-t]+v);
		}
	}
	
	cout << dy[lt];
	return 0;
}
