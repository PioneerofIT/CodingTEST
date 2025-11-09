#include <iostream>
using namespace std;

int dy[50];
int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	dy[1] = 1; // 1m 네트워크 선은 1가지 경우 
	dy[2] = 2; // 2m 네크 워크 선은 1+1, 2 2가지 경우
	
	for(int i=3; i<=n; i++)
	{
		dy[i] = dy[i-2] + dy[i-1]; //점화식	
	} 
	
	cout << dy[n] << "\n";
	 
	return 0;
}
