#include <iostream>
<<<<<<< HEAD
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
=======

using namespace std;

int main(int argc, char** argv) 
{
	int col, row,sum=0;
	int h, w; // �����
	int s, k; //������ ��� �� 
	int teri[51][51] = {0};
	
	cin >> h >> w; // �����
	
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
