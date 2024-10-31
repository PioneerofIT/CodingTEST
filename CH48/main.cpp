#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int data[9][9] = {0};
    const int rowcnt = 9;
    int col = 0, row = 0;
    vector<int> rowavg(rowcnt);
    
    // 각 행에 대해 데이터 입력받기 및 평균 계산
    for(row = 0; row < 9; row++) 
	{
        int res = 0;
        for(col = 0; col < 9; col++) 
		{
            cin >> data[row][col];
            res += data[row][col];
        }
        int avg = round(static_cast<double>(res) / rowcnt);
        rowavg[row] = avg; 
    }
    
    // 각 행별로 평균에 가장 가까운 값을 찾기
    for(row = 0; row < 9; row++)
	{
        int minDiff = 2147483647;  // 최소 차이값을 저장하기 위한 변수
        int closestValue = data[row][0]; // 평균에 가장 가까운 값 초기화

        for(col = 0; col < 9; col++)
		{
            int diff = abs(rowavg[row] - data[row][col]); // 평균과의 차이 계산
            if (diff < minDiff) 
			{
                minDiff = diff;
                closestValue = data[row][col];
            }
        }
        
        // 평균값과 그 평균에 가장 가까운 값을 출력
        cout << rowavg[row] << " " << closestValue << endl;
    }
    
    return 0;
}

