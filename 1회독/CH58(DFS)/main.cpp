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
		printf("%d ", v); //ÀüÀ§ Å½»ö 
		D(v*2);
//		printf("%d ", v); // ÁßÀ§ Å½»ö 
		D(v*2+1);
//		printf("%d ", v); // ÈÄÀ§ Å½»ö 
	}
}

int main(int argc, char** argv)
{
//	int n;
//	cin >> n;
	
	D(1);
	return 0;
}
