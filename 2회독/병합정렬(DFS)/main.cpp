#include <iostream>

using namespace std;
int n;
int arrNum[101];
int temp[101];

void Divide(int lt, int rt)
{
	if(lt < rt)
	{
		int mid = (lt+rt) / 2;
		
		Divide(lt, mid);
		Divide(mid+1, rt);
		
		int p1, p2, p3; // 병합 정렬을 위한 포인터
		
		p1 = lt;
		p2 = mid+1;
		p3 = lt; //temp 사용시
		
		while(p1 <= mid && p2 <= rt)
		{
			if( arrNum[p1] < arrNum[p2] ) 
			{
				temp[p3++] = arrNum[p1++];
			}
			else
			{
				temp[p3++] = arrNum[p2++];
			}
		}
		while(p1<=mid) temp[p3++] = arrNum[p1++];
		while(p2<=rt) temp[p3++] = arrNum[p2++];
		
		for(int i=lt; i<=rt; i++)
		{
			arrNum[i] = temp[i]; 	
		}
	}
}
int main(int argc, char** argv) 
{
	
	ios_base::sync_with_stdio(false);

	cin >> n;
	
	for(int i=1; i<=n; i++)
	{
		cin >> arrNum[i];	
	}
	
	Divide(1, n); // arr idx
	
	for(int i=1; i<=n; i++)
	{
		cout << arrNum[i] << " ";	
	}		
	
		
	return 0;
}
