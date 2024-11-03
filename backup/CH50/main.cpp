#include <iostream>
<<<<<<< HEAD
#include <vector>
#include <algorithm>
using namespace std;

/*2차원에서의 슬라이딩 윈도우 사용하기*/
int main(int argc, char** argv) 
{
	int H, W;
	cin >> H >> W;
	
	//기준을 잡자 보통 일반적으로 [행][열]이다. 
	vector<vector<int>> teri(H+1, vector<int>(W+1));
	
	int row  , col ; // row = H col = W  
	
	for(row=1; row<=H; row++ )
	{
		for(col=1; col<=W; col++)
=======

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
>>>>>>> c13fb275e0d95bda3b59e0d772890bc0f20c575b
		{
			cin >> teri[row][col];
		}
	}
	
<<<<<<< HEAD


	return 0;
=======
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
	
	
>>>>>>> c13fb275e0d95bda3b59e0d772890bc0f20c575b
}
