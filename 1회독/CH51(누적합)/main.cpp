#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dy[701][701] = {0};

int main(int argc, char** argv)
{
	int row, col;
	int h; //세로길이 row
	int w; //가로길이 col
	int s, k; // 세로, 가로 
	
	cin >> h >> w;
	
	
	for(row=1; row<=h; row++)
	{
		for(col=1; col<=w; col++)
		{
			int c;
			cin >> c;
			dy[row][col] = dy[row-1][col]+dy[row][col-1]-dy[row-1][col-1]+c;
		}
	}
	
	cin >> k >> s; // 2:row  3:col 
	
	int max = -2147894;
	
	for(row=k; row<=h; row++)
	{
		for(col=s; col<=w; col++)
		{
			int ismax = dy[row][col]-dy[row-k][col]-dy[row][col-s]+dy[row-k][col-s];
			if(ismax > max)
			{
				max = ismax;
			}
		}
	}
	
	
	cout << max;
	
//	for(row=1; row<=h; row++)
//	{
//		for(col=1; col<=w; col++)
//		{
//			cout << dy[row][col] << " ";	
//		}
//		cout << endl;	
//	} 
	return 0;
}
