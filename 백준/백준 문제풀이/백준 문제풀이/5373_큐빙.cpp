#include <iostream>
#include <vector>
using namespace std;
enum
{
	U = 0,
	D,
	F,
	B,
	L,
	R,
	FACE_MAX

};

//U: 윗 면, D: 아랫 면, F: 앞 면, B: 뒷 면, L: 왼쪽 면, R: 오른쪽 면
//흰색은 w, 노란색은 y, 빨간색은 r, 오렌지색은 o, 초록색은 g, 파란색은 b.
char cube[6][3][3];
int testCase;
void RotateFaceCw(char face)
{
	if (face == 'U')
	{
		char temp[3];
		for (int i = 0; i < 3; i++)
		{
			temp[i] = cube[F][0][i];

		}
		for (int i = 0; i < 3; i++)
		{
			cube[F][0][i] = cube[L][0][i];
			cube[L][0][i] = cube[B][0][2 - i];
			cube[B][0][2-i] = cube[R][0][i];
			cube[R][0][i] = temp[i];
		}
	}
	else if (face == 'D')
	{

	}
	else if (face == 'F')
	{

	}
	else if (face == 'B')
	{

	}
	else if (face == 'L')
	{

	}
	else if (face == 'R')
	{

	}
}
void RotateFaceCcw(char face)
{

}



int main()
{
	string color = "wyrogb";

	for (int i = 0; i < FACE_MAX; i++)
	{
		for (int row = 0; row < 3; row++)
		{
			for (int col = 0; col < 3; col++)
			{
				cube[i][row][col] = color[i];
			}
		}
	}

	cin >> testCase;
	while (testCase > 0)
	{
		testCase--;

		int tryCnt;
		cin >> tryCnt;

		for (int i = 0; i < tryCnt; i++)
		{
			string line;
			cin >> line;
			if (line[1] == '+')
			{
				RotateFaceCw(line[0]);
			}
			else
			{
				RotateFaceCcw(line[0]);
			}
				


		}

	}
	return 0;
}