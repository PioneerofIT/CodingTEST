#include <iostream>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) 
{
	
	string str1, str2;
	
	cin >> str1;
	cin >> str2;
	
	for(int i=0; i<str1.size(); i++)
	{
		for(int j=0; j<str2.size(); j++)
		{
			if(str1[i] == str2[j])
			{
				str2.erase(j,1);
			}
		}
				
	}
	if(str2.empty()) cout << "YES";
	else cout << "NO";
	return 0;
}
