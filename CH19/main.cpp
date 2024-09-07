#include <iostream>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv)
{
	int numStudent;
	int cntRes = 0;
	
	cin >> numStudent;
	
	int info[numStudent];
	
	for(int i=0; i<numStudent; i++)
	{
		cin >> info[i];		
	}
	
	for(int i=0; i<numStudent; i++)
	{
		bool isang = true; 
		if(i == numStudent-1) break;
		
		for(int j = i+1; j<numStudent; j++)
		{
			if(info[i] <= info[j]) 
			{
				isang = false;
				break;
			}
			
		}			
		
		if(isang) cntRes++; 
	}	
	
	cout << cntRes; 
	return 0;
}
