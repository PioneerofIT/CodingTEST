#include <iostream>
#include <vector>

using namespace std;

/*���� �κ� ��������*/
/*���� ���� ���� �����ϴ� �ɷ� ����*/
int main(int argc, char** argv)
/*{
	
	int N; // �ڿ��� ����
	cin >> N;

	vector<int> A(N);
	bool continueFlag = false;
	int Max = 0;
	int temp = 1;
	
	for(int i=0; i<N; i++)
	{
		cin >> A[i];
	}
	
	for(int i=0; i<N-1; i++ )
	{
		
		if( A[i] <= A[i+1])
		{
			temp ++;	
		}
		else
		{	
			if(temp > Max )
			{
				Max = temp;
				temp = 1;
			} 
		}
	}
	
	if(temp > Max) 
	{
		Max = temp;
	}
	
	cout << Max;
	
	
	 
	return 0;
	
}*/

{
	int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int Max = 0;
    int temp = 1;  // ���� �κ� ���� ������ ���̸� 1���� ����

    for (int i = 0; i < N - 1; i++) {
        if (A[i] <= A[i + 1]) {
            temp++;  // ���� ���� ���� ������ �۰ų� ������ ����
        } else {
            Max = max(Max, temp);  // �ִ� ���� ����
            temp = 1;  // temp ����
        }
    }

    // ������ ���� ���� ���� üũ
    Max = max(Max, temp);

    cout << Max;

    return 0;

}
	
