#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*2���������� �����̵� ������ ����ϱ�*/
int main(int argc, char** argv) 
{
	int H, W;
	cin >> H >> W;
	
	//������ ���� ���� �Ϲ������� [��][��]�̴�. 
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
