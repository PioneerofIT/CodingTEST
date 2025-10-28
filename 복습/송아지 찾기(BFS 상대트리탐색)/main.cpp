#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dist[3] = {-1, 1, 5};
int ch[10001]; // �湮�� �Ÿ� �ּҰŸ� ���� 
int minePos;
int cowPos;
int cnt =0; 


int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	queue<int> Q;

	cin >> minePos >> cowPos;
	Q.push(minePos);
	ch[minePos] = 1;
	
	while(!Q.empty())
	{
		int v = Q.front();
		Q.pop();
	

		for(int i=0; i<3; i++)
		{
			int nextLevelPos = v+dist[i];
			
			if (nextLevelPos < 1 || nextLevelPos > 10000) continue;
			
			if(ch[nextLevelPos] == 0)
			{
				ch[nextLevelPos] = ch[v] + 1;
				/*��ť�� ���� �� Ȯ�Ρ� �ϸ�
				ť�� �ְ� ���� Ȯ���ϸ�,
				�̹� ���� �������� ���� ������ ��ٷ��� �ؿ�.
				��, �� �� �� ���ʿ��ϰ� ť�� �־��ٰ� pop�ϴ� ������ ����.
				�� ����� ������ ��ȿ���� (�� ���� �ʾ���)*/
				if(nextLevelPos == cowPos)
				{
					cout << ch[nextLevelPos] -1;
					return 0;
				}
				Q.push(nextLevelPos);
			}
		}						
	}
	
	return 0;
}
