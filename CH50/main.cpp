#include <iostream>

using namespace std;

int main(int argc, char** argv) 
{
	int col, row,sum=0;
	int h, w; // 행과열
	int s, k; //현수의 행과 열 
	int teri[51][51] = {0};
	
	cin >> h >> w; // 행과열
	
	for(row=1; row<=h; row++)
	{
		for(col=1; col<=w; col++)
		{
			cin >> teri[row][col];
		}
	}
	
	cin >> s >> k;
	
	int max = -21470000;
	
	for(row=1; row<=h-s+1; row++)
	{
		for(col=1; col<=w-k+1; col++)
		{
			sum=0;
			for(int i=row; i<row+s; i++)
			{
				for(int j=col; j<col+k; j++)
				{
					sum += teri[i][j];	
				}	
			}
			if(sum > max)
			{
				max = sum;	
			}	
		}
	} 
	
	cout << max;
	return 0;
	
//	for(row=1; row<=h; row++)
//	{
//		for(col=1; col<=w; col++)
//		{
//			cout <<" " << teri[row][col];
//		}
//		cout << endl;
//	} 
	
	
}
