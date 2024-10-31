#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(int argc, char** argv)
{
	int data[9][9] = {0};
	const int rowcnt = 9;
	int col=0, row=0;
	int res=0;
	vector<int> rowavg(rowcnt);
	
	for(row=0; row<9; row++)
	{
		res = 0;
		for(col=0; col<9; col++)
		{
			cin >> data[row][col];
			res += data[row][col];
			
		}
		int avg = round(static_cast<double>(res) / rowcnt);;
		rowavg[row]=avg; 
		
	}
	
	
	
	for(row=0; row<9; row++)
	{
		
		int minDiff = 2147483647;  // 최소 차이값을 저장하기 위한 변수
        int closestValue = data[row][0];
		
		for(col=0; col<9; col++)
		{
			int diff = abs(rowavg[row] - data[row][col]); // 평균과의 차이 계산
            if (diff < minDiff)
			{
                minDiff = diff;
                closestValue = data[row][col];
			}
		}
		cout << rowavg[row] << " " << closestValue<< endl;

		
	}
	
	
	return 0;
}
