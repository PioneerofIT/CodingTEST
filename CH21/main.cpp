#include <iostream>
#include <string>
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// ����1. ��, ���� ���� ī���� ������ �ٲ� ���� ����. 
// ����2. ������ ���� ��� ������ ������ �̱� ����� �¸�
// ����3. ��� ���带 ����� �� ���
// ���� 3�� ���� ����x ��� �� ���� 1�� 

/*A�� B�� �þ���� ī���� ���ڰ� ������� �־��� ��, ������ ���ڰ� A���� B����, �Ǵ� ���
���� �����ϴ� ���α׷��� �ۼ��Ͻÿ�.*/ 
int main(int argc, char** argv)
{
	int A[10], B[10];
	int resA = 0; // ������ ���� 
	int resB = 0;
	bool compareflag = true;
	char latestWin;
	
	for(int i=0; i<10; i++)
	{
		cin >> A[i];
	}
	
	for(int i=0; i<10; i++)
	{
		cin >> B[i];
	}
	
	// ����� ��� ���� ����ó��
	for(int i=0; i<10; i++)
	{
		if(A[i] != B[i] ) compareflag = false; 	
	}
	
	if(compareflag)
	{
		cout << 10 <<" " << 10 << endl;
		cout << "D";
		return 0;		
	}
	
	for(int i=0; i<10; i++)
	{
		//case 1. A�¸� 
		if(A[i] > B[i])
		{
			resA += 3;
			latestWin = 'A';	
		}
		//case 2. B�¸� 
		else if(A[i] < B[i])
		{
			resB += 3;
			latestWin = 'B';
		}
		else if(A[i] == B[i])
		{
			resA += 1;
			resB += 1;	
		}
		
	}
	
	if(resA > resB)
	{
		cout << resA << " " << resB << endl;
		cout << "A";  
	}
	else if (resA < resB)
	{
		cout << resA << " " << resB << endl;
		cout << "B";  	
	}
	else if (resA == resB)
	{
		cout << resA << " " << resB << endl;
		cout << latestWin; 	
	}
	
		
	
	return 0;
}
