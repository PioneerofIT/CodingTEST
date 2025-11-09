#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{

	int asize;
	cin >> asize;

	vector<int> a(asize);
	for (int i = 0; i < asize; i++)
	{
		cin >> a[i];
	}

	int bsize;
	cin >> bsize;

	vector<int> b(bsize);
	for (int i = 0; i < bsize; i++)
	{
		cin >> b[i];
	}

	vector<int> c(asize + bsize);
	//--------------입력 초기화-------- 
	int p1 = 0, p2 = 0, p3 = 0;

	while (1)
	{
		if (p1 == asize || p2 == bsize)
			break;

		if (a[p1] < b[p2])
		{
			c[p3++] = a[p1++];
		}
		else if (a[p1] > b[p2])
		{
			c[p3++] = b[p2++];
		}
		else if (a[p1] == b[p2])
		{
			c[p3++] = a[p1++];
			c[p3++] = b[p2++];	
		}
	}

	if (asize > bsize)
	{
		int rest = asize - bsize;
		while (1)
		{
			c[p3++] = a[p1++];
			rest--;
			if(rest < 0)
				break;
		}
	}
	else
	{
		int rest = bsize - asize;
		while (1)
		{
			c[p3++] = b[p2++];
			rest--;
			if(rest < 0)
				break;
		}
	}

	for (int i = 0; i < c.size(); i++)
	{
		cout << c[i] << " ";
	}


	return 0;
}
