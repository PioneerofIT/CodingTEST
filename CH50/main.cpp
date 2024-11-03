#include <iostream>
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
		{
			cin >> teri[row][col];
		}
	}
	


	return 0;
}
