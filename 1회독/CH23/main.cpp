#include <iostream>
#include <vector>

using namespace std;

/*연속 부분 증가수열*/
/*값이 같을 떄는 증가하는 걸로 간주*/
int main(int argc, char** argv)
/*{
	
	int N; // 자연수 갯수
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
    int temp = 1;  // 연속 부분 증가 수열의 길이를 1에서 시작

    for (int i = 0; i < N - 1; i++) {
        if (A[i] <= A[i + 1]) {
            temp++;  // 현재 값이 다음 값보다 작거나 같으면 증가
        } else {
            Max = max(Max, temp);  // 최대 길이 갱신
            temp = 1;  // temp 리셋
        }
    }

    // 마지막 연속 증가 수열 체크
    Max = max(Max, temp);

    cout << Max;

    return 0;

}
	
