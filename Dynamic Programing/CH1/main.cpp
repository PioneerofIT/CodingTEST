#include <iostream>
using namespace std;

int dy[50];
int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	dy[1] = 1; // 1m ��Ʈ��ũ ���� 1���� ��� 
	dy[2] = 2; // 2m ��ũ ��ũ ���� 1+1, 2 2���� ���
	
	for(int i=3; i<=n; i++)
	{
		dy[i] = dy[i-2] + dy[i-1]; //��ȭ��	
	} 
	
	cout << dy[n] << "\n";
	 
	return 0;
}
