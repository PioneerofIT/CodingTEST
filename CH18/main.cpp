#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv)
{ 
	int N; //N�� ������ �ǽð� ����ġ
	int M; //�� ������ ��ûġ 
	cin >> N >> M;
	bool continueflag = false;

	vector<int> nSub; // ������
	int Cnt = 0;

	vector<int> Res;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		nSub.push_back(temp);

	}

	for (int i = 0; i < N; i++)
	{
		if (nSub[i] > 90)
		{
			continueflag = true;
			Cnt++;
		}
		else
		{
			continueflag = false;
			Res.push_back(Cnt);
			Cnt = 0;
		}
	}

	int max = 0;

	for (int i = 0; i < Res.size(); i++)
	{
		if (Res[i] > max) max = Res[i];
	}

	cout << max;



	return 0;
}
