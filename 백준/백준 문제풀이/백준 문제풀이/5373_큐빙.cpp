#include <iostream>
#include <vector>
using namespace std;

//0:U, 1:D, 2:F, 3:B, 4:L, 5:R 
//U=w, D=y, F=r, B=o, L=g, R=b
char cube[6][3][3];

void RotateFaccCw(char cube[][3], int cnt)
{
	
	char newCube[3][3];
	//memcpy(temp, cube, sizeof(temp));
	while (cnt > 0)
	{
		cnt--;

		for (int row = 0; row < 3; row++)
		{
			for (int col = 0; col < 3; col++)
			{
				newCube[col][2-row] = cube[row][col];
			}
		}
		memcpy(cube, newCube, sizeof(newCube));
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	/*for (int i = 0; i < 6; i++)
	{
		char initChar;
		if (i == 0) 
			initChar = 'w';
		else if (i == 1)
			initChar = 'y';
		else if (i == 2)
			initChar = 'r';
		else if (i == 3)
			initChar = 'o';
		else if (i == 4)
			initChar = 'g';
		else if (i == 5)
			initChar = 'b';

		for (int j = 0; j < 3; j++)
		{
			for (int z = 0; z < 3; z++)
			{
				cube[i][j][z] = initChar;
			}
		}
	
	}*/

	char test[3][3] = 
	{
		{'a','b','c'},
		{'d','e','f'},
		{'g','h','i'}
	};

	RotateFaccCw(test, 1);

	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			cout << test[row][col] << " ";
		}
		cout << endl;
	}

	return 0;
}