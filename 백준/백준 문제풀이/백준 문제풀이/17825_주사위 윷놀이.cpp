#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

const int DEPTH = 10;

int nextNode[33]; //시작 노드 Index ~ 도착 노드 Index
int blueNode[33];
int scoreBoard[33];
int maxScore = INT_MIN;

bool visited[DEPTH];
int dice[DEPTH];
int horse[4];


void initMap()
{
	for (int i = 0; i < 20; i++)
	{
		nextNode[i] = i + 1;
		scoreBoard[i] = i * 2 ;
	}
	nextNode[20] = 21;
	scoreBoard[20] = 40;
	scoreBoard[21] = 0;

	//파란색 지름길
	blueNode[5] = 22;
	scoreBoard[22] = 13;		nextNode[22] = 23;
	scoreBoard[23] = 16;		nextNode[23] = 24;
	scoreBoard[24] = 19;		nextNode[24] = 30;

	blueNode[10] = 25;
	scoreBoard[25] = 22;		nextNode[25] = 26;
	scoreBoard[26] = 24;		nextNode[26] = 30;

	blueNode[15] = 27;
	scoreBoard[27] = 28;		nextNode[27] = 28;
	scoreBoard[28] = 27;		nextNode[28] = 29;
	scoreBoard[29] = 26;		nextNode[29] = 30;

	scoreBoard[30] = 25;		nextNode[30] = 31;
	scoreBoard[31] = 30;		nextNode[31] = 32;
	scoreBoard[32] = 35;		nextNode[32] = 20; // 합류

}

int GetNextNode(int nowNode, int moveCnt)
{
	int next = nowNode;

	if (blueNode[next] != 0)
	{
		next = blueNode[next];
		moveCnt--;
	}

	while (moveCnt > 0)
	{
		if (next == 21) // 이동 중 도착노드에 도착했을 경우
		{
			break;
		}
		
		next = nextNode[next];
		moveCnt--;
	}

	return next;
}

bool IsOtherHorseThere(int finalNode, int horseIdx)
{
	if (finalNode == 21)
	{
		return false;
	}
	
	for (int i = 0; i < 4; i++)
	{
		if (i == horseIdx) continue;

		if (horse[i] == finalNode)
		{
			return true;
		}
	}
	return false;
}

void DoDfs(int depth, int currentScore)
{
	if (depth == DEPTH)
	{
		maxScore = max(maxScore, currentScore); // 최댓값 갱신
		return;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			int nowNode = horse[i];

			if (nowNode == 21) continue;

			int nextNodeAfterMove = GetNextNode(nowNode, dice[depth]);

			if (nextNodeAfterMove != 21 && IsOtherHorseThere(nextNodeAfterMove, i))
			{
				continue;
			}

			// --- 여기서부터 실제 이동 및 백트래킹 ---
			horse[i] = nextNodeAfterMove; // 1. 말 이동시킴 (상태 변경)

			// 2. 다음 주사위(depth+1)를 굴리러 재귀 호출 (점수 더해서 넘김)
			DoDfs(depth + 1, currentScore + scoreBoard[nextNodeAfterMove]);

			horse[i] = nowNode; // 3. 탐색을 마치고 돌아오면 말의 위치를 원래대로 복구 (백트래킹)
		}
	}


}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	initMap();

	for (int i = 0; i < DEPTH; i++)
	{
		cin >> dice[i];
	}

	DoDfs(0,0);

	cout << maxScore;

	return 0;
}