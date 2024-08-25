#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
/*C Style*/
//int main(int argc, char** argv)
//{
//	char a[100], b[100];
//	int pos=0;
//	gets(a);
//	
//	for(int i=0; a[i]!='\0'; i++)
//	{
//		if(a[i] != ' ')
//		{
//			if(a[i]>= 65 && a[i]<=90) //대문자이면 
//			{
//				b[pos++] = a[i] + 32;
//			}
//			else
//			{
//				b[pos++] = a[i];
//			}
//		}
//	}
//	
//	b[pos] = '\0';
//	cout << b;
//	return 0;
//}
/*C++ Style*/
int main(int argc, char** argv)
{
	string input;
	string output;
	
	getline(cin, input);
	
	
	for(char ch : input)
	{
		if(ch != ' ')
		{
			if(ch >= 'A' && ch<= 'Z') //대문자이면 
			{
				output += ch + 32;	
			}
			else
			{
				output += ch;		
			}
		}
	}
	
	cout << output;
}
