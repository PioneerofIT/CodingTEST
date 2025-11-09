#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dist[3] = {-1, 1, 5};
int ch[10001]; // 방문겸 거리 최소거리 점프 
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
				/*“큐에 넣은 뒤 확인” 하면
				큐에 넣고 나서 확인하면,
				이미 다음 루프에서 꺼낼 때까지 기다려야 해요.
				즉, 한 번 더 불필요하게 큐에 넣었다가 pop하는 과정이 생김.
				→ 결과는 같지만 비효율적 (한 스텝 늦어짐)*/
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
