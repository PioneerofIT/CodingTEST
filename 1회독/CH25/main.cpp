#include <iostream>
#include <vector>
#include <algorithm>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
// 1. 같은 점수가 입력될 경우 높은 석차로 동일 처리 

/*내 풀이
int main(int argc, char** argv) 
{
	int Num;
	cin >> Num;
	int temp = Num;
	vector<int> Data(Num);
	vector<int> grade(Num);
	
	for(int i=0; i<Num; i++)
	{
		cin >> Data[i];
	}
	
	for(int i=0; i<Data.size(); i++)
	{
		for(int j=0; j<Data.size(); j++)
		{
			if( i == j ) continue;
			
			if(Data[i] >= Data[j])	temp --;
			
		}
		
		cout << temp << " ";
		temp = Num;
	}
	return 0;
}*/

//답안 
// 내 풀이와 비교하였을 때 내 풀이는 논리적인 오류가 존재..
// 풀이 코드가 직관적이고 이해하기 쉬운 코드 
int main(int argc, char** argv) 
{
	
	int a[200], b[200], n;
	cin >> n;
	
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
		b[i] = 1;	
	} 
	
	for(int i=1; i<=n; i++) 
	{
		for(int j=1; j<=n; j++)
		{
			if(a[j]>a[i]) b[i] ++;
		}
	}
	
	for(int i=1; i<=n; i++)
	{
		cout << b[i] << " ";
	}
	return 0;
}
