#include <iostream>
#include <vector>
using namespace std;

void D(int v)
{
	if(v>7)
	{
		return;
	}
	else
	{
		printf("%d ", v); //���� Ž�� 
		D(v*2);
//		printf("%d ", v); // ���� Ž�� 
		D(v*2+1);
//		printf("%d ", v); // ���� Ž�� 
	}
}

int main(int argc, char** argv)
{
//	int n;
//	cin >> n;
	
	D(1);
	return 0;
}
