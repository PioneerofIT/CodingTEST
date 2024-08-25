#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
	string sCin, sOut;
	
	cin >> sCin;
	
	for(int i=0; i<sCin.size(); i++)
	{
		if(sCin[i] >= '0' && sCin[i] <= '9') 
		{
			sOut.push_back(sCin[i]);	
		}	
	}
	int nResult = stoi(sOut);
	int nCountResult = 0;
	
	for (int j=1; j<=nResult; j++)
	{
		if(nResult % j == 0) nCountResult ++; 	
	}
	
	cout << nCountResult;
	
	
		
	return 0;
}
