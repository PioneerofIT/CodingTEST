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
    
    // �� �࿡ ���� ������ �Է¹ޱ� �� ��� ���
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
    
    // �� �ະ�� ��տ� ���� ����� ���� ã��
    for(row = 0; row < 9; row++)
	{
        int minDiff = 2147483647;  // �ּ� ���̰��� �����ϱ� ���� ����
        int closestValue = data[row][0]; // ��տ� ���� ����� �� �ʱ�ȭ

        for(col = 0; col < 9; col++)
		{
            int diff = abs(rowavg[row] - data[row][col]); // ��հ��� ���� ���
            if (diff < minDiff) 
			{
                minDiff = diff;
                closestValue = data[row][col];
            }
        }
        
        // ��հ��� �� ��տ� ���� ����� ���� ���
        cout << rowavg[row] << " " << closestValue << endl;
    }
    
    return 0;
}

